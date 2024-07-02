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

int findNumber(int x, int y)
{

    int low = 1;
    int high = 2e18;
    bool found = false;
    int ans;
    while (low < high)
    {
        if (found)
            break;
        int mid = low + (high - low) / 2;
        if (mid % x == y % mid)
        {

            found = true;
            ans = mid;
            high = mid;
        }
        else
        {

            if (mid % x < y % mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }

    return ans;
}
vector<int> primes;

void sieve_of_eratosthenes(int n)
{
    std::vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= n; ++p)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p)
    {
        if (is_prime[p])
        {
            primes.push_back(p);
        }
    }
}
bool get(int mid, int n, int k, std::vector<int>& pref) {
    int64_t lcm = 1;
    for (int i = 0; i < mid; ++i) {
        int p = primes[i];
        int power = static_cast<int>(std::log(k) / std::log(p));
        int64_t prime_power = std::pow(p, power);

        // Check for potential overflow
        if (lcm > n / 2 / prime_power) {
            return false;
        }

        lcm *= prime_power;
    }
    return pref[mid - 1] <= n;
}
void comderoP0612()
{

 int n,k; cin>>n>>k;
    int temp=n;
    vector<int> ans;
    while(k-sz(ans)!=3)
    {
        ans.pb(1);
        temp--;
    }
    if(temp&1) 
    {
        ans.pb(1);
        ans.pb((temp-1)/2);
        ans.pb((temp-1)/2);
    }
    else if(temp%4)
    {
        ans.pb(2);
        ans.pb((temp-2)/2);
        ans.pb((temp-2)/2);
    }
    else
    {
        ans.pb(temp/2);
        ans.pb(temp/4);
        ans.pb(temp/4);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
   
    while (t--)
        comderoP0612();
    return 0;
}
