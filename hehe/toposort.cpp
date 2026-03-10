#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()

void solveQ13() {

    int n;
    cin >> n;

    vector<int> id(n), parent(n);

    for(int i = 0; i < n; i++)
        cin >> id[i] >> parent[i];

    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> indeg;
    unordered_set<int> nodes;

    for(int i = 0; i < n; i++) {
        nodes.insert(id[i]);
        indeg[id[i]] = 0;
    }

    for(int i = 0; i < n; i++) {

        if(parent[i] != -1) {

            if(nodes.find(parent[i]) == nodes.end()) {
                cout << "Orphan record detected\n";
                return;
            }

            adj[parent[i]].pb(id[i]);
            indeg[id[i]]++;
        }
    }

    queue<int> q;

    for(auto &x : nodes)
        if(indeg[x] == 0)
            q.push(x);

    vector<int> order;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        order.pb(node);

        for(auto child : adj[node]) {

            indeg[child]--;

            if(indeg[child] == 0)
                q.push(child);
        }
    }

    if(sz(order) != n) {
        cout << "Cycle detected\n";
        return;
    }

    for(auto x : order)
        cout << x << " ";

    cout << "\n";
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while (t--)
        solveQ13();

    return 0;
}