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
vi v(n);
cin>>v;
int m;
cin>>m;
unordered_map<int , pii> mp;
mp[v[0]] = {0,1};

for(int i=1 ; i<n-1 ; i++){
    if(abs(v[i-1]-v[i]) > abs(v[i+1]-v[i])){
        mp[v[i]] = {abs(v[i-1]-v[i]),1};
    }
    else{
        mp[v[i]]={1 , abs(v[i+1]-v[i])};
    }
    
}
mp[v[n-1]] = {1,0};
int sumRight[n]={0};
sumRight[0] = mp[v[0]].second;
for(int i=1 ; i<n ; i++){
 sumRight[i] = sumRight[i-1] + mp[v[i]].second;
}
int sumLeft[n]={0};
sumLeft[n-1] = mp[v[n-1]].first;
for(int i=n-1 ; i>=1 ; i--){
 sumLeft[i-1] = sumLeft[i] + mp[v[i-1]].first;
}
for(int i=0 ; i<m ; i++){
    int j , k;
    int sum=0;
    cin>>j>>k;
    if(j<k){
       cout<<sumRight[k-1]-sumRight[j-1] + mp[v[j-1]].ss - mp[v[k-1]].ss<<endl;
       continue;
    }
    if(k<j){
            cout<<sumLeft[k-1]-sumLeft[j-1] - (mp[v[k-1]].ff - mp[v[j-1]].ff)<<endl;
            continue;
    }
    cout<<sum<<endl;
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