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

void comderoP0612(){
    int n,k,c;
    cin>>n>>k>>c;
    //make adj
    vi adj[n+1];
    for(int i=1 ; i<=n-1 ; i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(k<=c){
        // using dfs find the farthest node
        int Ones_farthestnode=1;
        int maxi_dist = 0;
        function<void(int, int, int)> dfs = [&](int node, int parent, int distance) -> void {
            if (distance > maxi_dist) {
                maxi_dist = distance;
                Ones_farthestnode = node;
            }
            for (auto &adjNode : adj[node]) {
                if (adjNode != parent) {
                    dfs(adjNode, node, distance + 1);
                }
            }
        };
        dfs(1, -1, 0);
        cout<<maxi_dist*k<<endl;
    }
    else{
        
        map<int,int> distMap;
        int Ones_farthestnode=1;
        int maxi_dist = 0;
        function<void(int, int, int)> dfs = [&](int node, int parent, int distance) -> void {
            distMap[node] = distance;
            if (distance > maxi_dist) {
                maxi_dist = distance;
                Ones_farthestnode = node;
            }
            for (auto &adjNode : adj[node]) {
                if (adjNode != parent) {
                    dfs(adjNode, node, distance + 1);
                }
            }
        };

    
        dfs(1, -1, 0);
        // deb(Ones_farthestnode);
        int farthest_of_Ones_farthest = Ones_farthestnode;
        int maxi = 0;
        int ans=0;
        function<void(int, int, int)> dfsfromFarthest = [&](int node, int par, int distance) -> void {
            ans = max(ans , distance*k - distMap[node]*c);
            if (distance > maxi) {
                maxi = distance;
                farthest_of_Ones_farthest = node;
            }
            for (auto &adjNode : adj[node]) {
                if (adjNode != par) {
                    dfsfromFarthest(adjNode, node, distance + 1);
                }
            }
        };

        dfsfromFarthest(Ones_farthestnode, -1, 0);

        cout<<ans<<endl;
    }
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) comderoP0612();
    return 0;
}
