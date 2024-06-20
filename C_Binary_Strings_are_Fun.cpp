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
// we need to go by dp here coz combinatorics takes up the complexity exponential
//lets consider that dp[m] stores that m lemgth prefix is a good extension then dp[m+1] would be dp[m]*2 when s[m]==s[m+1]
// bcoz lets take 1_0_1 and 1_0_1_1 in first case we want 3 ones and in second case 4 ...so if dp[m] is good extension ans s[m]==s[m+1] median of m length prefix is s[m] 
// means m length prefix contains s[m] more than m times.. so dp[m+1] to be a good extension s[m]==s[m+1] so m+1 leth prefix would also contain s[m+1] greter than m+1 times

// now what if s[m]!=s[m+1]
// same example 1_0_1 and 1_0_1_0....
// if dp[m] is good then m length prefix that creates 2m-1 length extension is good only if s[m] is median and s[m] occours >=m times 
// for dp[m+1] to be good its median should be s[m+1] means s[m+1] that is not equal to s[m] must occour more than m+1 times and as dp[m] is good so s[m] in extension of m+1 ie.. 2(m+1)-1 must also occour >=m times
// so for both the conditions to be true that s[m] occours more tha m times and s[m+1] must occour >=m+1 times there is only one possiblity that s[m] in first xtension length 2m-1 must occour exactly m times and 
// s[m+1] in whole pefix 2(m+1) -1 must ocoour exactly m+1 times 
// soonly one possiblity that s[m]!=s[m+1];
int sm=1;
int prev = 1;
int curr ; 
for(int i=1 ; i<sz(s) ; i++){
    if(s[i]==s[i-1]){
        curr = (prev%mod2 * 2) % mod2 ;
        prev = curr;
    }
    else{
        curr = 1;
        prev = curr;
    }
    sm = (sm%mod2 + curr%mod2)%mod2;
}
cout<<sm<<endl;

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