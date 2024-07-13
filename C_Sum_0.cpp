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
#define ha cout << "Yes" << endl
#define na cout << "No" << endl

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;


void read_input(int &n, vector<int> &left, vector<int> &right, vector<int> &xudi) {
    cin >> n;
    left.resize(n);
    right.resize(n);
    xudi.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> left[i] >> right[i];
        xudi[i] = left[i];
    }
}


bool adjust_values(int n, vector<int> &left, vector<int> &right, vector<int> &xudi, long long &current_sum) {
    for (int i = 0; i < n; ++i) {
        if (current_sum == 0) break;

        if (current_sum > 0) {
            int decrease = min(current_sum, (long long)(xudi[i] - left[i]));
            xudi[i] -= decrease;
            current_sum -= decrease;
        } else {
            int increase = min(-current_sum, (long long)(right[i] - xudi[i]));
            xudi[i] += increase;
            current_sum += increase;
        }
    }
    return current_sum == 0;
}


void print_result(bool balanced, const vector<int> &xudi) {
    if (balanced) {
        ha;
        for (int i = 0; i < sz(xudi); ++i) {
            cout << xudi[i] << " ";
        }
        cout << endl;
    } else {
        na;
    }
}

void comderoP0612() {
    int n;
    vector<int> left, right, xudi;
    read_input(n, left, right, xudi);

    long long current_sum = accumulate(all(xudi), 0LL);
    bool balanced = adjust_values(n, left, right, xudi, current_sum);
    print_result(balanced, xudi);
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    comderoP0612();
    return 0;
}
