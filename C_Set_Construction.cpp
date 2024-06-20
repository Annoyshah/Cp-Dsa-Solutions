
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

 
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
class DisjointSet {
    
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void dfs(int node, vi adj[], vi& vis, vector<vi>& vec , set<int>& st2 , set<int>& st3) {
    vis[node] = 1;
    for(auto &it : adj[node]){
        int nonu = *st3.begin();
        vi vu;
        vu = vec[node];
        vu.pb(nonu);
        st3.erase(nonu);
        vec[it] = vu;
        st2.insert(nonu);
        if(!vis[it]) dfs(it , adj , vis , vec , st2 , st3);
    }

}

void comderoP0612() {
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, 0));
    set<pii> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] == '1') {
                st.insert({i + 1, j + 1});
            }
        }
    }
    for (auto &it : st)
        deb(it);
    vi adj[n + 1];
    // DisjointSet dsu(n + 1);
    for (auto &it : st) {
        // adj[it.ss].pb(it.ff);
        adj[it.ff].pb(it.ss);
        // dsu.unionBySize(it.ss, it.ff);
    }
    vi vis(n + 1, 0);
    vi ve;
    map<int,int> mp;
    for(int i=1 ; i<=n ;i++) mp[i]=0;
    for(int i=1 ; i<=n ; i++){
        deb(adj[i]);
        for(auto &ti : adj[i]){
            mp[ti]++;
        }
       
    }
    for(auto &it : mp){
        if(it.ss==0) ve.pb(it.ff);
    }
    deb(ve);
    vector<vi> vec(n);
    set<int> included;
    for(int i=0 ;i<sz(ve) ; i++){
        included.insert(i+1);
        vec[ve[i]].pb(i+1);
        deb(vec[ve[i]]);
        
    }
    set<int> notIncluded;

    for(int i=1 ; i<=n ; i++){
        if(included.find(i)==included.end()){
            notIncluded.insert(i);
        }
    }
    for(auto &it : ve){
        dfs(it , adj , vis , vec , included , notIncluded );
    }
    for(int i=0 ; i<vec.size() ; i++){
        for(auto &it : vec[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
   
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) comderoP0612();
    return 0;
}