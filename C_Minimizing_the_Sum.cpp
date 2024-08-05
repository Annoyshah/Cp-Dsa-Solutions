/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &it : v)
        in >> it;
    return in;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &it : v)
        os << it << " ";
    return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    cin >> p.first >> p.second;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    cout << p.first << " " << p.second;
    return os;
}
template <typename T1, typename T2>
void maxn(T1 &a, T2 b) { a = max(a, b); }
template <typename T1, typename T2>
void maxx(T1 &a, T2 b) { a = max(a, b); }

#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout << #x << "=" << x << endl;
#define pii pair<int, int>
#define vi vector<int>
#define repL(i, a, b) for (int i = (a); i < (b); i++)

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
vector<vector<int>> dp;

int f(int idx, int k, vi& vec) {
    int n = sz(vec);
    if (idx >= n) return 0;
    if (dp[idx][k] != -1) return dp[idx][k];

    int sum = vec[idx] + f(idx + 1, k, vec);  // Continue with the next element

    for (int blocksize = 1; blocksize < k + 1; blocksize++) {
        if(idx+blocksize >= n) break;
        int mini = vec[idx];
    
        for (int i = idx; i < min(n, idx + blocksize + 1); i++) {
            mini = min(mini, vec[i]);
        }
        sum = min(sum, mini*(blocksize+1) + f(idx + blocksize + 1, k - (blocksize), vec));
    }

    return dp[idx][k] = sum;
}

void comderoP0612()
{
    int n, k;
    cin >> n >> k;
    vi vec(n, 0);
    cin >> vec;
 // dp vs greedy
 // lets say 
 // 10 9 9 3 1 is the aaray we are given with
 // k valkue is small ,minimum is asked so dp works here (n*k) as well ss n*k*k both are acceptable here
 // carefully if w eobserve we get that the mimum elements make a block of lenght L1
 // L1 length block having the value of each element as the minimum element 
 // another minium element converts it to L2 block of minimum element
 // for converting each eleemnt of L1 block to value of minimum element it takes L1-1 operations
 // for converting each element of L2 block to value of minimum element it takes L2-1 operatoins
 // 3 4 6 12 5
 // states :
 // 5 says i will not perform any operation , i will live alone 
 // so ans will be 5 + f(ind-1 ,  k);
 // if 5 says i will covert my left neighbouring ele to 5
 // ans will be 5*2 + f(ind-1 , k-1); // length 2 ka block (2-1) = 1  operation (len-1) opr to change all elements to minimum element of thatv block
 // if 5 says i will pair with my 2 neighbouring elements
 // ans will be 5*3 + f(ind-1 , k-2) // length of block 3 , opr 2
 int ans = 0;
 dp = vector<vector<int>>(n+1 , vector<int>(k+1 , -1));
 ans = f(0,k,vec);
 cout<<ans<<endl;


}
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--)
        comderoP0612();
    return 0;
}