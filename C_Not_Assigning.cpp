/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }
 
#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout<<#x<<"="<<x<<endl;
#define pii pair<int,int> 
#define vi vector<int>
#define repL(i, a, b) for(int i = (a); i < (b); i++)
// observation was that for a binary number n , its lowest significant bit is always its divisor so
// for examle 1110(14) an be converted to 1100(12) and ten to 1000(8)..Now as soon as we reach the neraest two's power i.e 8 in this example 
// another observation was that 2^k+1 is always divisible by 2^k an so on we will move till 2 by dividing the given number by 2 and then push_back 1 to the vec and sz(vec) will be our answer 

// Accepted Solution 
int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
void dfs(int node, int parent, unordered_map<pii, int>& mp, vector<int>& vis, bool& ok, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (auto n : adj[node]) {
        if (!vis[n]) {
            if (ok) {
                mp[{node, n}] = 2;
                mp[{n,node}] = 2;
                ok = false;
                dfs(n, node, mp, vis, ok, adj);
            } else {
                mp[{node, n}] = 5;
                mp[{n , node}] = 5;
                ok = true;
                dfs(n, node, mp, vis, ok, adj);
            }
        }
    }
}

void comderoP0612() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1); // Local adjacency list
    unordered_map<pii, int> mp;
    vector<pii> edges;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        mp[{x, y}] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> vis(n + 1, 0);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            dfs(i, -1, mp, vis, ok, adj);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (mp.count({it.first.first, it.first.second}) && it.second != 0) {
            cout << it.second << " ";
        }
        
        if (mp.count({it.first.second, it.first.first}) && it.second != 0) {
            cout << it.second << " ";
        }
    }
    cout << endl;
}


int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--) comderoP0612();
    return 0;
}