
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
void dfs(int vis[] , int node, int& mini, map<int, int>& mp) {
 
    vis[node] = 1;
    mini = min(mini, mp[node]); 
   
    for (auto &it : adjList[node]) {
        if (!vis[it]) {
            dfs(vis, it , mini, mp);
        }
    }
}

void comderoP0612() {
int n ; 
cin>>n;
vi v(n);
cin>>v;
sort(all(v));
int pref[n];
pref[0]=v[0];
for(int i=1 ; i<n ; i++){
    pref[i] = pref[i-1] + v[i];
}
int cnt=2;
// deb(v);
for(int i=1 ; i<n ; i++){
    // deb(i);
    int it = lower_bound(v.begin(), v.end(), pref[i])-v.begin();
    if(it<n && it!=i+1){
        pref[i+1] = pref[i] + v[it];
        swap(v[it],v[i+1]);
      
        cnt++;
    }
    if(it<n && it==i+1){
        cnt++;
        // deb(cnt);
    }
    pref[i+1] = pref[i] + v[i+1];
}
if(n>=2){
    cout<<cnt<<endl;
}
else{
    cout<<1<<endl;
}
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    comderoP0612();
    return 0;
}