/* ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it : v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it : v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a, b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a, b); }

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
#define repL(i, a, b) for(int i = (a); i < (b); i++)

const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

int can_make_all_1s(string str) {
    int n = sz(str);
    for (int k = n; k > 0; k--) {
        vector<int> v(n, 0); // Store the indices of the last segment index till we have flipped
        string s = str; // Make a copy of the input string
        int flipped = 0;
        bool canbedone = true;

        for (int i = 0; i < n; ++i) {
            flipped ^= v[i];
            if (flipped == 1) {
                s[i] = (s[i] == '0') ? '1' : '0';
            }
            if (s[i] == '0') {
                flipped ^= 1;
                if (i + k > n) {
                    canbedone = false;
                    break;
                } else if (i + k < n) {
                    v[i + k] = 1; // Mark the end of the segment to reverse the flip
                }
            }
        }
        if (canbedone) {
            return k;
        }
    }
    return 1LL;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = can_make_all_1s(s);
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
