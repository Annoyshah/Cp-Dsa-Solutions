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

//    observation i observed : 
//    order of elements does not matter , it better to sort them or get a frequncy map of them 
//    you can just sort them out then also the minimum codt would not change 
//    you can't do it greedily .. 00001223 its benifincial to take out number 1 first to have minimum score so you cannot have any choice that i will take out higher or ssmaller number first
//    so its good to go dp here
//    its always benificial to get out all the occourences of a number while adding to score so mp[num-1]*mex + num will be addd to the score
//    i have n numbers the mex of n numbers can never be greater than n-1
//    0 1 2 3999 3000 288 (mex=>3)
//    0 1 2 3 4 5 (mex=>n-1)
//    mex of above array can never increase more than n-1
//    numers only betwen 0 to n matter // we only count there frequency

//    what I wasnt able to think :
//    states of dp here
//    dp[num][mex] => the numbers with a mex of mex and a[i]<=num
//    so i have 2 choices here
//     i can remove all the occources of a[i]=num or leave it and move to another a[j]<=num and j<i
int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;
    // deb(vec);
    // Calculate frequency count
    vi cnt(n + 1, 0);
    for (int i = 0; i < sz(vec); i++) {
        if (vec[i] < n ) {
            cnt[vec[i]]++;
        }
    }

    // Calculate overall mex of the array
    int mex=0;
    while (cnt[mex] > 0) mex++;
    if (mex == 0) {
        cout << 0 << endl;
        return;
    }
    
  n = mex;
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case
    for (int i = 0; i <= n; i++) {
        dp[0][i] = (cnt[0] - 1) * i ;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            // Not-take case
            dp[i][j] = dp[i - 1][j];
            // Take case
            int take = (cnt[i]-1) * j + i + dp[i - 1][i];
            dp[i][j] = min(dp[i][j], take);
        }
    }
    
    cout << dp[n - 1][n] << endl;

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