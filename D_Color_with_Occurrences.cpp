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

struct FenwickTree {
    vector<int> BIT;
    int n;

    FenwickTree(int size) {
        n = size;
        BIT.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    void range_update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
};

bool coversWholeRange(int n, vector<pair<int, int>>& segments) {
    FenwickTree ft(n + 1); // Fenwick Tree for 1-based indexing

    for (auto& seg : segments) {
        ft.range_update(seg.first + 1, seg.second + 1, 1); // Increment range by 1
    }

    for (int i = 0; i < n; ++i) {
        if (ft.query(i + 1) == 0) { // Check if position i is covered
            return false;
        }
    }

    return true;
}

void comderoP0612() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec[i] = str;
    }

    vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.pb(i);
    }

    vector<vector<int>> indexes(n);
    for (int k = 0; k < sz(vec); k++) {
        auto str = vec[k];
        for (int i = 0; i <= (sz(s) - sz(str)); i++) {
            if (s.substr(i, sz(str)) == str) {
                indexes[k].pb(i);
            }
        }
    }

    int mini = LLONG_MAX;
    vector<int> min_perm;

    do {
        vector<pii> segments;
        int cnt = 0;
        bool done = false;
        for (auto &it : perm) {
            for (auto &idx : indexes[it]) {
                segments.pb({idx, idx + sz(vec[it]) - 1});
                cnt++;
                if (coversWholeRange(sz(s), segments)) {
                    done = true;
                    break;
                }
            }
            if (done) break;
        }

        if (done && cnt < mini) {
            mini = cnt;
            min_perm = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    if (mini == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << mini << endl;
        int ct = 0;
        for (int i = 0; i < min_perm.size(); i++) {
            for (auto idx : indexes[min_perm[i]]) {
                cout << min_perm[i] + 1 << " " << idx + 1 << endl;
                ct++;
                if (ct == mini) break;
            }
            if (ct == mini) break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        comderoP0612();
    }
    return 0;
}
