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
#define repL(i, a, b) for(int i = (a); i < (b); i++)

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

void comderoP0612() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = 'L' + s;
    s = s + 'L';
    int idx = 0;
    while (idx <= n + 1) {
        if (idx == n + 1) {
            cout << "YES" << endl;
            return;
        }
        if (s[idx] == 'L') {
            int lastL = idx;
            int lastswim = -1;
            int jump = m;
            for (int j = idx + 1; j <= n + 1 && jump > 0; j++) {
                if (s[j] == 'L') {
                    lastL = j;
                }
                if (s[j] == 'W') {
                    lastswim = j;
                }
                jump--;
            }
            if (lastL != idx) {
                idx = lastL;
            } else {
                if (lastswim != -1) {
                    idx = lastswim;
                } else {
                    cout << "NO" << endl;
                    return;
                }
            }
        } else if (s[idx] == 'W') {
            int canswim = k;
            if (k == 0) {
                cout << "NO" << endl;
                return;
            }
            int j = idx;
            int lstswim = idx;
            bool foundL = false;
            for (; j <= n + 1 && canswim > 0; j++) {
                if (s[j] == 'L') {
                    idx = j;
                    foundL= true;
                    break;
                } else if (s[j] == 'W') {
                    lstswim = j;
                    canswim--;
                } else if (s[j] == 'C') {
                    cout << "NO" << endl;
                    return;
                }
            }
           if(foundL){
            k = canswim;
                continue;
           }
           else{
             if (canswim == 0 && s[lstswim + 1] == 'L') {
                idx = lstswim + 1;
                k = canswim;
            } else if (canswim == 0 && s[lstswim + 1] != 'L') {
                cout << "NO" << endl;
                return;
            }
           }
        } else {
            cout << "NO" << endl;
            return;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}