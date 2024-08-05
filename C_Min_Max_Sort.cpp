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

const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

void comderoP0612() {
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;

    vi v;
    for (int i = 1; i <= n; i++) {
        v.pb(i);
    }

    vector<pii> pairs;
    int i = 0;
    int j = sz(v) - 1;
    while (i <= j) {
        pairs.pb({v[i], v[j]});
        i++;
        j--;
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[vec[i]] = i;
    }

    sort(all(pairs), greater<pii>());

 
    int l = mp[pairs[0].ff];
    int r = mp[pairs[0].ss];
    int opr = 0;
    if (n % 2 == 1) {
            opr = n/2;
        for (int i = 1; i < pairs.size(); i++) {
            if (mp[pairs[i].ff] < mp[pairs[i].ss] && (mp[pairs[i].ff] <= l && mp[pairs[i].ss] >= r)) {
                l = mp[pairs[i].ff];
                r = mp[pairs[i].ss];
                opr--;
            } else {
                break;
            }
        }
    } else {
         opr = n/2;
        if (l < r){
            opr--;
            for (int i = 1; i < pairs.size(); i++) {
            if (mp[pairs[i].ff] < mp[pairs[i].ss] && (mp[pairs[i].ff] < l && mp[pairs[i].ss] > r)) {
                l = mp[pairs[i].ff];
                r = mp[pairs[i].ss];
                opr--;
            } else {
                // opr++;break;
                cout<<opr<<endl;
                return;
            }
        }
        }
        else{
           cout<<opr<<endl;
                return;
        }
      
    }

    cout << opr << endl;
}

int32_t main() {
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
