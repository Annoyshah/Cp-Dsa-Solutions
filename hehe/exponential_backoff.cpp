#include "bits/stdc++.h"
#include <thread>
#include <mutex>
using namespace std;

class RateLimitedPoller {
    int           normalDelay;      // base poll interval (seconds)
    int           maxBackoff;       // max backoff (seconds)
    int           currentDelay;     // current delay (increases on 429)
    int           consecutiveOK;    // count of consecutive successes
    int           resetAfter;       // reset backoff after this many successes
    mutex         mtx;

public:
    RateLimitedPoller(int normalDelay = 5, int maxBackoff = 300, int resetAfter = 3)
        : normalDelay(normalDelay), maxBackoff(maxBackoff),
          currentDelay(normalDelay), consecutiveOK(0), resetAfter(resetAfter) {}

    // simulates API call — returns 200 or 429
    int callAPI() {
        // simulate: 429 randomly 30% of time
        return (rand() % 10 < 3) ? 429 : 200;
    }

    void poll() {
        lock_guard<mutex> lock(mtx);

        int status = callAPI();

        if (status == 429) {
            consecutiveOK = 0;                              // reset success counter

            // double the delay, cap at maxBackoff
            currentDelay = min(currentDelay * 2, maxBackoff);

            cout << "[429] Rate limited! Next poll in " << currentDelay << "s\n";
        }
        else {
            consecutiveOK++;
            cout << "[200] Success! consecutiveOK=" << consecutiveOK << "\n";

            // reset backoff after N consecutive successes
            if (consecutiveOK >= resetAfter) {
                currentDelay  = normalDelay;
                consecutiveOK = 0;
                cout << "[RESET] Backoff reset to " << normalDelay << "s\n";
            }
        }
    }

    int getNextPollDelay() {
        lock_guard<mutex> lock(mtx);
        return currentDelay;
    }

    // run polling loop for given number of polls
    void run(int totalPolls) {
        for (int i = 1; i <= totalPolls; i++) {
            cout << "\n--- Poll #" << i << " ---\n";
            poll();
            int delay = getNextPollDelay();
            cout << "Waiting " << delay << "s...\n";
            this_thread::sleep_for(chrono::seconds(delay));
        }
    }
};

int main() {
    srand(time(0));

    RateLimitedPoller poller(
        5,    // normal delay = 5s
        300,  // max backoff  = 5 min
        3     // reset after  = 3 consecutive OK
    );

    poller.run(8);   // run 8 polls
    return 0;
}


// **Sample Output:**

// --- Poll #1 ---
// [200] Success! consecutiveOK=1
// Waiting 5s...

// --- Poll #2 ---
// [200] Success! consecutiveOK=2
// Waiting 5s...

// --- Poll #3 ---
// [429] Rate limited! Next poll in 10s
// Waiting 10s...

// --- Poll #4 ---
// [429] Rate limited! Next poll in 20s
// Waiting 20s...

// --- Poll #5 ---
// [200] Success! consecutiveOK=1
// Waiting 20s...

// --- Poll #6 ---
// [200] Success! consecutiveOK=2
// Waiting 20s...

// --- Poll #7 ---
// [200] Success! consecutiveOK=3
// [RESET] Backoff reset to 5s
// Waiting 5s...

// --- Poll #8 ---
// [200] Success! consecutiveOK=1
// Waiting 5s...


// **Core logic — what to say in interview:**

// 3 things to track:
// ┌─────────────────────────────────────────────┐
// │ currentDelay   → how long to wait next      │
// │ consecutiveOK  → count of successes in row  │
// │ maxBackoff     → cap so delay doesn't grow  │
// │                  forever                    │
// └─────────────────────────────────────────────┘

// On 429:
//   currentDelay = min(currentDelay * 2, maxBackoff)
//   consecutiveOK = 0

// On 200:
//   consecutiveOK++
//   if consecutiveOK >= 3 → reset currentDelay = normalDelay


// **Backoff progression:**

// 429 → 5  * 2 = 10s
// 429 → 10 * 2 = 20s
// 429 → 20 * 2 = 40s
// 429 → 40 * 2 = 80s
// ...capped at 300s (5 min)