
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
int tt=1;
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

map<int,bool> vis;
set<int> st;
void dfs(int idx , int n , int k){
  
   if(idx>=n) return;
   if(idx<0) return;
   if(vis[idx]) return;
   st.insert(idx);
   vis[idx] = true;
   dfs(idx+k  , n , k);
   dfs(idx+k+1  , n , k);
   dfs(idx-k , n , k);
   dfs(idx-k-1  , n , k);

}
void comderoP0612(){
 int n,k;
 cin>>n>>k;
 string s;
 cin>>s;
 string t;
 cin>>t;
 vis.clear();
// op solution
// we can move onto any point from any point forward and backward by swapping k or k+1 units
// using vis mark visitd ...taking out possiblities of all indexes and trying them out to have a posible combination
// we will go on chekig for every index and take out the swappping posssiblitis
// i.e.. ind+k , ind+k+1 , ind-k , ind-k-1
// now keep these idixes onto set 
// now check the values of s and t at thse indices
// if by any possible rearrangement we can match those indices of s and t  
// vi vis(n+1,0);
// set<int> st;
for(int i=0 ; i<n ; i++){
    if(!vis[i]){
        st.clear();
        dfs(i ,n , k);
        // my solution - map solution
        // the real OG one 
        map<int,int> mp1;
        map<int,int> mp2;
        for(auto &it : st){
            mp1[s[it]]++;
            mp2[t[it]]++;
        }
        for(auto &it : st){
            if((!mp1[t[it]]) || (!mp2[s[it]])){
                cout<<"NO"<<endl;
                return;
            }
            else{
                mp1[t[it]]-=1;
                mp2[s[it]]-=1;
            }
        }
        
    }
}
cout<<"YES"<<endl;
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