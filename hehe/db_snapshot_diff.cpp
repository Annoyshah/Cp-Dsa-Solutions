#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb push_back
#define sz(v) (int)v.size()
#define pii pair<int,int>          // {id, timestamp}

struct Result {
    vector<pii> added;
    vector<pii> modified;
    vector<pii> deleted;
};

Result dbSnapshotDiff(vector<pii>& before, vector<pii>& after) {
    unordered_map<int,int> beforeMap;   // id -> timestamp

    for (auto& [id, ts] : before)
        beforeMap[id] = ts;

    Result res;

    for (auto& [id, ts] : after) {
        if (beforeMap.find(id) == beforeMap.end())
            res.added.pb({id, ts});                      // in after, not in before
        else if (beforeMap[id] != ts)
            res.modified.pb({id, ts});                   // in both, different timestamp
        beforeMap.erase(id);                             // mark as visited
    }

    for (auto& [id, ts] : beforeMap)
        res.deleted.pb({id, ts});                        // leftover = deleted

    return res;
}

void solve() {
    int n;
    cout << "Enter size of before: ";
    cin >> n;

    vector<pii> before(n), after;
    cout << "Enter id and timestamp pairs:\n";
    for (auto& [id, ts] : before) cin >> id >> ts;

    int m;
    cout << "Enter size of after: ";
    cin >> m;
    after.resize(m);
    for (auto& [id, ts] : after) cin >> id >> ts;

    Result res = dbSnapshotDiff(before, after);

    cout << "\nAdded:    ";
    for (auto& [id, ts] : res.added)    cout << "{" << id << "," << ts << "} ";

    cout << "\nModified: ";
    for (auto& [id, ts] : res.modified) cout << "{" << id << "," << ts << "} ";

    cout << "\nDeleted:  ";
    for (auto& [id, ts] : res.deleted)  cout << "{" << id << "," << ts << "} ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


// **Logic in 3 steps:**

// before: {1,100}, {2,200}, {3,300}
// after:  {1,100}, {2,250}, {4,400}

// Step 1 — build beforeMap:
//   beforeMap = {1:100, 2:200, 3:300}

// Step 2 — iterate after:
//   id=1, ts=100 → found, same ts     → unchanged, erase from map
//   id=2, ts=250 → found, diff ts     → MODIFIED,  erase from map
//   id=4, ts=400 → not found          → ADDED

// Step 3 — leftover in beforeMap:
//   id=3, ts=300 → never visited      → DELETED