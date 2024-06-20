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
int query(vi vec){
int n = vec.size();
cout<<"? "<<n<<" ";
for(int i=0 ; i<n ; i++) cout<<vec[i]<<" ";
cout<<endl;
int res;
cin>>res;
return res;
}
void comderoP0612(){
int n , k;
cin>>n>>k;
vi v(n);
vector<vector<int>> subsets(k);
for(int i=0 ; i<n ; i++) v[i]=i+1;
for(int i=0 ;i<k ; i++){
    int c;
    cin>>c;
    for(int j=0 ; j<c ; j++){
        int x;
        cin>>x;
        subsets[i].pb(x);
    }
}
int maxi = query(v);
// log(base 2)(1000) = 10 and number of queries are not allowed more than 12 so we will proceed with binary search as query ~= log(n);
int l = 0;
int r = k-1;
while(l+1<r){
    int mid = (l+r)/2;
    vi vtr;
    for(int i=0  ; i<=mid ; i++){
        for(int j=0 ; j<=sz(subsets[i])-1 ;j++){
            vtr.pb(subsets[i][j]);
        }
    }
    if(query(vtr)==maxi){
        r = mid;
    }
    else{
        l = mid;
    }
}
set<int> st;
for(int i=1 ; i<=n ; i++){
    st.insert(i);
}
for(int i=0 ;i<=subsets[l].size()-1 ; i++){
    st.erase(subsets[l][i]);
}
vi finalQuery;
for(auto &x : st) finalQuery.pb(x);
int x = query(finalQuery);
vi ans(k+1);
for(int i=1 ; i<=k ; i++) ans.pb(maxi);
ans[l] = x;
cout<<"! ";
for(int i=1 ; i<=k ; i++) cout<<ans[i]<<" ";
cout<<endl;
string s;
cin>>s;

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