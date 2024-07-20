/* ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it : v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it : v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
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

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

void comderoP0612() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    vector<vi> seq(k, vi(n, 0));
    
    for(int i = 0; i < k; i++) {
        vi vec(n);
        cin >> vec;
        seq[i] = vec;
    }
   
    vi indegree(n + 1, 0);
    vector<set<int>> adj(n + 1);
   
    for(int i = 0; i < k; ++i) {
        for(int j = 1; j < n - 1; j++) {
            if (adj[seq[i][j]].insert(seq[i][j + 1]).second) {
                indegree[seq[i][j + 1]]++;
            }
        }
    }
   
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
   
    vi topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.pb(node);
        for(auto it = adj[node].begin(); it != adj[node].end(); ++it) {
            indegree[*it]--;
            if(indegree[*it] == 0) {
                q.push(*it);
            }
        }
    }
       
    if(sz(topo) == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while(t--) comderoP0612();
    return 0;
}
