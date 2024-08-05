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

void comderoP0612() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi v1(k), v2(k);
    cin >> v1 >> v2;
    int q;
    cin >> q;
    vi numbers(q);
    cin >> numbers;

    // map to store ranges for each index in v2
    map<int, vector<pii>> mp;

    for (auto &x : numbers) {
        auto it = lower_bound(v2.begin(), v2.end(), x);

        if (it != v2.end() && *it >= x) {
            int idx = distance(v2.begin(), it);
            while (idx >= 0 && v1[idx] > x) {
                idx--;
            }

            if (idx >= 0 && v1[idx] <= x && v2[idx] >= x) {
                int a = min(x, v1[idx] + v2[idx] - x);
                int b = max(x, v1[idx] + v2[idx] - x);

                if (a <= b) {
                    mp[idx].pb({a, b});
                }
            }
        }
    }

    for (auto &it : mp) {
        if (sz(it.ss) == 0) continue;

        int sizu = sz(it.ss);
        sort(all(it.ss));
        pii processed = it.ss.back();

        if (sizu % 2 == 0) it.ss.pop_back();
        else {
            int x = it.ss.back().ff;
            int y = it.ss.back().ss;
            while (x < y) {
                swap(s[x - 1], s[y - 1]);
                x++;
                y--;
            }
        }

        while (!it.ss.empty()) {
            if (sz(it.ss) % 2 == 0) {
                processed = it.ss.back();
                it.ss.pop_back();
            } else {
                int low = it.ss.back().first;
                int high = it.ss.back().second;
                int abhiff = processed.ff;
                int abhiss = processed.ss;
                while (low < abhiff) {
                    swap(s[low - 1], s[high - 1]);
                    low++;
                    high--;
                }

                processed = it.ss.back();
                it.ss.pop_back();
            }
        }
    }
    cout << s << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
