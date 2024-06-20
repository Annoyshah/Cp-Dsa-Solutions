
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

vector<int> adjList[1000006];
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
class DSU {
private:
    vector<int> parent;
    vector<int> size;
   

public:
 vector<int> superiors;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        superiors.resize(n+1,-1);
        for (int i = 1; i <=n; ++i) {
            parent[i] = i; // Each element is initially its own parent
        }
    }

    // Find operation with path compression
   int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]); // Recursively find the root
        // Update superiors[x]
        parent[x] = root; // Path compression
    }
    return parent[x];
}
    int findSuperiors(int x){
       
        if(parent[x]==x) return 0;
        if(superiors[x]!=-1) return superiors[x];
         return superiors[x] = 1+findSuperiors(parent[x]);
    }


    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
        
    }
};
void comderoP0612(){
 int n,q;
 cin>>n>>q;
 DSU dsu(n+1);
 for(int i=0; i<q ; i++){
    int type;
    cin>>type;
    if(type==1){
        int x,y;
        cin>>x>>y;
        dsu.merge(x,y);
        continue;
    }
    else if(type==2){
        int c;
        cin>>c;
        cout<<dsu.findSuperiors(c)<<endl;
        continue;
    }

 }
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    // int t=1;
    comderoP0612();
    return 0;
}