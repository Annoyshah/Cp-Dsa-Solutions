#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(v) (int)v.size()

vector<string> deduplicate(vector<string>& stream, bool keepFirst) {
    vector<string> result;

    if (keepFirst) {
        // ---- KEEP FIRST OCCURRENCE ----
        unordered_set<string> seen;
        for (auto& rec : stream) {
            if (seen.find(rec) == seen.end()) {
                seen.insert(rec);
                result.pb(rec);
            }
        }
    } else {
        // ---- KEEP LAST OCCURRENCE ----
        // two-pass approach
        unordered_map<string, int> lastIdx;   // id -> last seen index

        // pass 1: record last index of each element
        for (int i = 0; i < sz(stream); i++)
            lastIdx[stream[i]] = i;

        // pass 2: only keep element if current index == last index
        for (int i = 0; i < sz(stream); i++)
            if (lastIdx[stream[i]] == i)
                result.pb(stream[i]);
    }

    return result;
}

void solve() {
    int n;
    cout << "Enter stream size: ";
    cin >> n;

    vector<string> stream(n);
    cout << "Enter records: ";
    for (auto& s : stream) cin >> s;

    int choice;
    cout << "keepFirst? (1=true / 0=false): ";
    cin >> choice;

    vector<string> res = deduplicate(stream, choice == 1);

    cout << "Output: [";
    for (int i = 0; i < sz(res); i++)
        cout << "\"" << res[i] << "\"" << (i+1 < sz(res) ? ", " : "");
    cout << "]\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


// **How each case works:**

// Input: [A, B, A, C, B, D]

// keepFirst = true  (unordered_set, single pass)
// ─────────────────────────────────────────────
// A → not seen → ADD   seen={A}
// B → not seen → ADD   seen={A,B}
// A → seen     → SKIP
// C → not seen → ADD   seen={A,B,C}
// B → seen     → SKIP
// D → not seen → ADD   seen={A,B,C,D}

// Output: [A, B, C, D] ✓

// keepFirst = false  (unordered_map, two pass)
// ────────────────────────────────────────────
// Pass 1 - record last index:
//   lastIdx = {A:2, B:4, C:3, D:5}

// Pass 2 - keep only if i == lastIdx[elem]:
//   i=0 A → lastIdx[A]=2 ≠ 0 → SKIP
//   i=1 B → lastIdx[B]=4 ≠ 1 → SKIP
//   i=2 A → lastIdx[A]=2 = 2 → ADD
//   i=3 C → lastIdx[C]=3 = 3 → ADD
//   i=4 B → lastIdx[B]=4 = 4 → ADD
//   i=5 D → lastIdx[D]=5 = 5 → ADD

// Output: [A, C, B, D] ✓