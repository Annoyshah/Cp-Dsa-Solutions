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

int power(int x, int y, int p) {
    int res = 1;
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p; // Change x to x^2
    }
    return res;
}

// One-liner function to compute (a/b) % m
int modDivide(int a, int b, int m) {
    return (a * power(b, m - 2, m)) % m;
}

void comderoP0612() {
    int n, m;
    cin >> n >> m;
    vi vec(n);
    cin >> vec;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[vec[i]]++;
    }
    vi v;
    for (auto &it : mp) {
        v.pb(it.ff);
    }
    sort(all(v));
    int ans = 0;
    vi prefix(sz(v), 0);
    prefix[0] = mp[v[0]];
    for (int j = 1; j < sz(v); j++) {
        prefix[j] = (mp[v[j]] * prefix[j - 1]) % mod;
    }
    for (int i = 0; i < sz(v); i++) {
        int left = v[i] + m - 1;
        int it = lower_bound(all(v), left) - v.begin();
        while (it < sz(v) && v[it] > left && it >= i) {
            --it;
        }
        if (it < sz(v) && it - i + 1 == m) {
            ans = (ans + (modDivide(prefix[it], prefix[i], mod) * mp[v[i]]) % mod) % mod;
        }
    }
    cout << ans % mod << endl;
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
