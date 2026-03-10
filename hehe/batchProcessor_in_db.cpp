#include "bits/stdc++.h"
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

class BatchProcessor {
    int                    batchSize;
    int                    timeoutSec;
    vector<string>         currentBatch;
    vector<vector<string>> completedBatches;
    mutex                  mtx;
    atomic<bool>           running;
    thread                 timerThread;
    time_t                 lastAddTime;

    void flushBatch(string reason) {
        // NOTE: call only when mtx is already locked
        if (currentBatch.empty()) return;
        cout << "Batch flushed (" << reason << "): [";
        for (int i = 0; i < (int)currentBatch.size(); i++)
            cout << currentBatch[i] << (i+1 < (int)currentBatch.size() ? ", " : "");
        cout << "]\n";
        completedBatches.push_back(currentBatch);
        currentBatch.clear();
    }

    void timerLoop() {
        while (running) {
            this_thread::sleep_for(chrono::seconds(1));  // check every second
            lock_guard<mutex> lock(mtx);
            if (!currentBatch.empty()) {
                time_t now = time(nullptr);
                if ((int)(now - lastAddTime) >= timeoutSec)
                    flushBatch("timeout");
            }
        }
    }

public:
    BatchProcessor(int batchSize, int timeoutSec)
        : batchSize(batchSize), timeoutSec(timeoutSec), running(true) {
        lastAddTime  = time(nullptr);
        timerThread  = thread(&BatchProcessor::timerLoop, this);
    }

    void add(string record) {
        lock_guard<mutex> lock(mtx);
        currentBatch.push_back(record);
        lastAddTime = time(nullptr);
        if ((int)currentBatch.size() >= batchSize)
            flushBatch("size");
    }

    void shutdown() {
        running = false;
        timerThread.join();                 // wait for timer to stop
        lock_guard<mutex> lock(mtx);
        flushBatch("shutdown");             // flush leftovers
    }

    vector<vector<string>> getBatches() {
        lock_guard<mutex> lock(mtx);
        return completedBatches;
    }
};

int main() {
    BatchProcessor bp(3, 2);   // batchSize=3, timeout=2sec

    bp.add("A");
    bp.add("B");
    bp.add("C");               // → size flush

    bp.add("D");
    this_thread::sleep_for(chrono::seconds(3));  // → timeout flush

    bp.add("E");
    bp.shutdown();             // → shutdown flush

    cout << "\n--- All Batches ---\n";
    int i = 1;
    for (auto& batch : bp.getBatches()) {
        cout << "Batch " << i++ << ": [";
        for (int j = 0; j < (int)batch.size(); j++)
            cout << batch[j] << (j+1 < (int)batch.size() ? ", " : "");
        cout << "]\n";
    }
}


// **Expected Output:**

// Batch flushed (size):     [A, B, C]
// Batch flushed (timeout):  [D]
// Batch flushed (shutdown): [E]

// --- All Batches ---
// Batch 1: [A, B, C]
// Batch 2: [D]
// Batch 3: [E]


// **What to say in interview — 4 key points:**

// 1. mutex          → only 1 thread touches batch at a time
// 2. atomic<bool>   → safe flag to stop timer thread
// 3. timerThread    → background thread checks timeout every second
// 4. shutdown()     → join thread first, then flush leftovers


// **3 flush triggers:**

// add()      → size  >= batchSize   → flushBatch("size")
// timerLoop  → time  >= timeoutSec  → flushBatch("timeout")
// shutdown() → remaining records    → flushBatch("shutdown")