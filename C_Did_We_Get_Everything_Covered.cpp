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

void comderoP0612()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vi dp;
    set<int> st;
    set<char> needed;
    for (int j = 0; j < k; j++) {
        needed.insert(j + 'a');
    }
    for (int i = 0; i < sz(s); i++) {
        st.insert(s[i] - 'a');
        if (sz(st) == k) {
            dp.pb(i);
            st.clear();
        }
    }
    st.clear();
    vector<char> order;
    for (auto &it : dp) {
        if (st.find(s[it] - 'a') == st.end()) {
            order.pb(s[it]);
            st.insert(s[it] - 'a');
        }
    }
    // for(auto &it : st) deb(it);
    if (sz(order) == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        string str = "";
        for (auto &it : order) {
            str += it;
        }
        char ch;
        for (auto &need : needed) {
            // if(sz(str)==n) break;
            if (st.find(need - 'a') == st.end()) {
                ch = need ;
                break;
            }
        }
        deb(ch);
        while(sz(str)!=n){
            str+=ch;
        }
        cout << str << endl;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        comderoP0612();
    }
    return 0;
}
