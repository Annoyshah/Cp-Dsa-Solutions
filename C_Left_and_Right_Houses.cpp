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
int n;
cin>>n;
string s;
cin>>s;
map<int , pair<int,int>> mp;
int cnt1 = 0; int cnt2=0;
for(int i=0 ; i<n ; i++){
 cnt1+= (s[i]=='0');
 cnt2+= (s[i]=='1');
 mp[i+1] = {cnt1 , cnt2};
//  deb(mp[i+1]);
}
int i=1;
vi vec;
for(  ; i<n ; i++){
    
    if((mp[i].ff >= ceil(static_cast<double>(i)/2)) && (mp[n].ss - mp[i].ss >= ceil(static_cast<double>(n-i)/2))) vec.pb(i);
    
}
if(sz(vec)==0){
    if(mp[n].ss >= ceil(static_cast<double>(n)/2)) vec.pb(0);
    else if(mp[n].ff >= ceil(static_cast<double>(n)/2)) vec.pb(n);
}
// deb(vec);
vector<pair<int,double>> vec2;
double mini = 1e9;
for(auto &it : vec){
    mini = min(mini , abs((static_cast<double>(n)/2 - it)));
    vec2.pb({it ,abs(static_cast<double>(n)/2 - it)});
}
sort(all(vec2));
// deb(vec2);
// deb(mini);
for(auto &it : vec2){
    if(it.ss == mini) {
        cout<<it.ff<<endl;
        return;
}
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