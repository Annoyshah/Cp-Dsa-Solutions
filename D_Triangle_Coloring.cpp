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
int tc = 1;
// Find position of MSB in n. For example if n = 17,
// then position of MSB is 4. If n = 7, value of MSB
// is 2
int msbPos(ll n)
{
    int msb_p = -1;
    while (n)
    {
        n = n >> 1LL;
        msb_p++;
    }
    return msb_p;
}

// Function to find Bit-wise & of all numbers from x
// to y.
ll andOperator(ll x, ll y)
{
    ll res = 0; // Initialize result

    while (x && y)
    {
        // Find positions of MSB in x and y
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);

        // If positions are not same, return
        if (msb_p1 != msb_p2)
            break;

        // Add 2^msb_p1 to result
        ll msb_val = (1LL << msb_p1);
        res = res + msb_val;

        // subtract 2^msb_p1 from x and y.
        x = x - msb_val;
        y = y - msb_val;
    }

    return res;
}
bool isPerfectSquare(int d)
{
    if (d < 0)
    {
        return false; // Negative numbers cannot be perfect squares
    }

    int sqrtD = static_cast<int>(std::sqrt(d));
    return (sqrtD * sqrtD == d);
}
int bssqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int left = 1, right = x, ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
// const unsigned long long mod2 = 998244353;
const int MAX = 3e5;  // Adjust this value based on the problem constraints

vector<unsigned long long> fact(MAX + 1);
vector<unsigned long long> invFact(MAX + 1);

// Function to compute x^y % p in O(log y)
unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p) {
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y & 1) {
            res = (res * x) % p;
        }

        // y must be even now
        y = y >> 1; // y = y / 2
        x = (x * x) % p; // Change x to x^2
    }
    return res;
}

// Function to precompute factorials and their inverses
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % mod2;
    }
    invFact[MAX] = power(fact[MAX], mod2 - 2, mod2);
    for (int i = MAX - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod2;
    }
}

// Function to compute nCr % mod2 using precomputed factorials and inverses
unsigned long long nCr(unsigned int n, unsigned int r) {
    if (r > n) {
        return 0;
    }
    return fact[n] * invFact[r] % mod2 * invFact[n - r] % mod2;
}
int processFindPermutation(vi &v){
    set<int> st;
    for(int i=0 ; i<sz(v) ; i++){
        st.insert(v[i]);
    }
    if(sz(st)==3){
        return 2;
    }
    else if(sz(st)==2){
        auto it = st.end();
        --it;
        int cnt=0;
        for(auto &itr : v){
            if(itr==*it){
                cnt++;
            }
        }
        if(cnt==2){
            return 2;
        }
        else{
            return 4;
        }
    }
    else if(sz(st)==1){
        return 6;
    }
}

void comderoP0612()
{
    int n;
    cin>>n;
    vi vec(n,0);
    cin>>vec;
    vi ans;
    for(int i=0 ; i<=n-3 ;i+=3){
        vector<int> v;
        for(int j=i ; j<i+3 ;  j++){
         
          v.push_back(vec[j]);
        }
        ans.pb(processFindPermutation(v));
        
    }
    int mul=1;
    for(auto &it : ans){
        mul = (mul%mod2)*((it/2)%mod2);
    }
    int numberofIslands = n/3;
    mul = (mul%mod2)*(nCr(numberofIslands , numberofIslands/2)%mod2);
    cout<<mul%mod2<<endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    precomputeFactorials();
    comderoP0612();
    return 0;
}