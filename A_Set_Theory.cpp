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
#define endl "\n"

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
vi primes;

void sieve(int n, set<int> &st)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p] && st.find(p) == st.end() && p != 2)
        {
            primes.pb(p);
        }
    }
}
int check[1000050];
void comderoP0612()
{
    int n;
    cin >> n;
    // deb(n);
    vi vec(n, 0);
    cin >> vec;
    // deb(vec);

    int num = 1;
    cout<<"YES"<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<num<<" ";
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n ; k++){
                int val = num + vec[j] - vec[k];
                if(val>=1 and val<1000000) check[val] = true;

            }
        }
        while(check[num]) num++;
    }
    cout<<endl;
    for (int i = 1; i <= 1000000; i++) check[i] = false;
    
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
