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
 
template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it : v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it : v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { cout << p.first << " " << p.second; return os; }
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
#define repL(i, a, b) for (int i = (a); i < (b); i++)
 
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

bool range_and(int l, int r, const vector<vector<int>>& prefixsum, int k) {
    int ans = 0; 
    // deb(r);
    for (int i = 63; i >= 0; i--) {
        int total_bits = prefixsum[r][i] - (l > 0 ? prefixsum[l - 1][i] : 0);
        if (total_bits == (r - l + 1)) {
            ans |= (1LL << (63 - i));
        }
    }
    // deb(ans);
    return ans >= k;
}

void comderoP0612() {
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;

    int q;
    cin >> q;

    vector<vector<int>> prefixsum(n, vector<int>(64, 0));
    for (int bits = 63; bits >= 0; bits--) {
        prefixsum[0][63 - bits] = (vec[0] >> bits) & 1;
    }

    for (int i = 1; i < n; i++) {
        for (int bits = 63; bits >= 0; bits--) {
            int num = (vec[i] >> bits) & 1;
            prefixsum[i][63 - bits] = prefixsum[i - 1][63 - bits] + num;
        }
        // deb(prefixsum[i]);
    }

    while (q--) {
        int l1, k;
        cin >> l1 >> k;
        l1--;
        // deb(l1);
        int l = l1;
        int r = n - 1;
        bool found = false;

        while (l <= r) {
            int mid = (l + r) >> 1LL;
            // deb(mid);
            if (range_and(l1, mid, prefixsum, k)){
                found = true;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        if (found) {
            cout<<l<<" ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
