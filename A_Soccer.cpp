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
int bssqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    
    int left = 1, right = x, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
void comderoP0612()
{
     int x ,y;
      cin>>x>>y;
      int p , q;
      cin>>p>>q;
      bool found = false;
      if(x==y or p==q) {
        cout<<"No"<<endl;
        return;
      }
      else if(y==q){
        if(x<=y or y<=p){
            cout<<"No"<<endl;
            return;
        }
        else{
            cout<<"Yes"<<endl;
            return;
        }
      }
      else{
       if(x<y and y<p and q > x and q>p){
           cout<<"Yes"<<endl;
           return;
       }
       else if(y<x and x<q and p>y and p>q){
        cout<<"Yes"<<endl;
        return;
       }
       else if(y<x and y<p and q>x and q<p){
        cout<<"No"<<endl;
        return;
       }
       else if( y < x and q > x and p>y and p<q){
        cout<<"No"<<endl;
        return;
       }

      }
    
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