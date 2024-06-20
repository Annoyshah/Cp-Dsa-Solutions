
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

bool check(int mid, vector<vi>& pref, vector<int>& vec) {
    int n = sz(vec);
    if (mid > n) return false;
    
    int q = mid - 1;
    int prev_or = 0;
    for (int j = 20; j >= 0; j--) {
        if (pref[q][j] > 0) prev_or |= (1 << j);
    }

    bool found = false;
    for (int i = 1; i + mid - 1 < n; i++) {
        int cur_or = 0;
        int k = i + mid - 1;
        for (int j = 20; j >= 0; j--) {
            if ((pref[k][j] - pref[i - 1][j]) > 0) cur_or |= (1 << j);
        }
        if (prev_or != cur_or) {
            found = true;
            break;
        }
    }
    return !found;
}

void comderoP0612() {
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;

    vector<vector<int>> pref(n, vector<int>(21, 0)); // 21 instead of 20 to handle 20 bits from 0 to 20
    for (int j = 20; j >= 0; j--) {
        pref[0][j] = (vec[0] >> j) & 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 20; j >= 0; j--) {
            pref[i][j] = pref[i - 1][j] + ((vec[i] >> j) & 1);
        }
    }

    int l = 0;
    int r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        bool c = check(mid, pref, vec);
        if (c) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}


int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}