#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define vi vector<int>
#define pii pair<int,int>
#define pip pair<int,pii>          // {value, {array_index, element_index}}

vi mergeKSorted(vector<vi>& arrays) {
    priority_queue<pip, vector<pip>, greater<pip>> pq;

    for (int i = 0; i < sz(arrays); i++)
        if (sz(arrays[i]) > 0)
            pq.push({arrays[i][0], {i, 0}});

    vi result;
    while (!pq.empty()) {
        pip top = pq.top(); pq.pop();

        int val     = top.first;
        int arrIdx  = top.second.first;
        int elemIdx = top.second.second;

        result.pb(val);

        if (elemIdx + 1 < sz(arrays[arrIdx]))
            pq.push({arrays[arrIdx][elemIdx + 1], {arrIdx, elemIdx + 1}});
    }
    return result;
}

void solve() {
    int k;
    cout << "Enter K (number of arrays): ";
    cin >> k;

    vector<vi> arrays(k);
    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter size of array " << i+1 << ": ";
        cin >> n;
        arrays[i].resize(n);
        cout << "Enter " << n << " sorted elements: ";
        for (int j = 0; j < n; j++) cin >> arrays[i][j];
    }

    vi res = mergeKSorted(arrays);

    cout << "Merged: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}