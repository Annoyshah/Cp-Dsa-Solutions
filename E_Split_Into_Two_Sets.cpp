/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a, b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a, b); }

#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout << #x << "=" << x << endl;
#define pii pair<int, int>
#define vi vector<int>
#define repL(i, a, b) for(int i = (a); i < (b); i++)
#define ha cout << "YES" << endl
#define na cout << "NO" << endl

const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int te = 1;
int tc = 1;


vector<bool> vis1;
vector<bool> vis2;
vector<int> dp;

bool f(int idx, vector<pii>& vec, vector<bool>& vis1, vector<bool>& vis2) {
    int x = vec[idx].ff;
    int y = vec[idx].ss;
    if(x == y) return false;
   if (idx == sz(vec)-1) {
        return (!vis1[x] && !vis1[y]) || (!vis2[x] && !vis2[y]);
    }
    if(dp[idx]!=-1) return dp[idx];

    bool ok1 = false;
    bool ok2 = false;

   
    if (!vis1[x] && !vis1[y]) {
        vis1[x] = vis1[y] = true;
        ok1 = f(idx + 1, vec, vis1, vis2);
        vis1[x] = vis1[y] = false;
    }

    if (!vis2[x] && !vis2[y]) {
        vis2[x] = vis2[y] = true;
        ok2 = f(idx + 1, vec, vis1, vis2);
        vis2[x] = vis2[y] = false;
    }

    return dp[idx] = (ok1 || ok2);
}
 bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 0;  // Start coloring with color 0

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto neighbor : graph[current]) {
                if (visited[neighbor] == -1) {
                    // Color with opposite color
                    visited[neighbor] = !visited[current];
                    q.push(neighbor);
                } else if (visited[neighbor] == visited[current]) {
                    // If neighbor has the same color, graph is not bipartite
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v, -1);  // -1 means unvisited

        for (int i = 0; i < v; i++) {
            if (visited[i] == -1 && !graph[i].empty()) {
                if (!bfs(i, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

void comderoP0612() {
    int n;
    cin >> n;
    vector<pii> vec(n);
    vector<vector<int>> adj(n+1);
    bool invalid = false;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[i] = {x, y};
        adj[x].pb(y);
        adj[y].pb(x);

        if(sz(adj[x]) > 2 || sz(adj[y]) > 2 || x == y) {
            invalid = true;
        }
    }

    if (invalid) {
        na;
        return;
    }

    // vis1.assign(n + 1, false);
    // vis2.assign(n + 1, false);
    // dp.assign(n + 1, -1);

    // if (f(0, vec, vis1, vis2)) {
    //     ha;
    // } else {
    //     na;
    // }
    if(isBipartite(adj)){
        ha;
        return;
    }
    else{
        na;
        return;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--){
         te++;
        comderoP0612();
       
    }
    return 0;
}
