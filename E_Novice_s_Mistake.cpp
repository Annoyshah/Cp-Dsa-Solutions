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

vector<int> res;

// Function to generate results based on the problem description
void fun(int n) {
    string str = to_string(n);
    int numDigits = sz(str);
    int maxLimit = n * 1e4;

    if (numDigits == 1) {
        int tmp = n;
        res.pb(n);
        tmp*=10;
        while (tmp <= maxLimit) {
            tmp += str[0]-'0';
            res.pb(tmp);
            tmp*=10;
        }
    } else if (numDigits == 2) {
        int first = str[0] - '0';
        int second = str[1] - '0';
        int turn = 1;
        int tmp = n;
        res.pb(n);
        while (tmp <= maxLimit) {
            if (turn & 1) {
                tmp*=10;
                tmp+=first;
            } else {
                tmp *= 10;
                tmp += second;
            }
            res.pb(tmp);
            turn++;
        }
    } else {
        int first = str[0] - '0';
        int second = str[1] - '0';
        int third = str[2] - '0';
        int turn = -1;
        res.pb(n);
        int tmp = n*10;;
        while (tmp <= maxLimit) {
            if (turn == -1) {
                tmp += first;
                turn = 0;
            } else if (turn == 0) {
                tmp += second;
                turn = 1;
            } else {
                tmp += third;
                turn = -1;
            }
            
            res.pb(tmp);
            tmp*=10;
        }
    }
}


void comderoP0612() {
    int n;
    cin >> n;
    res.clear();
    deb(n);
    fun(n);
    // for(auto &it : res) deb(it);
    vector<pii> op;
    for (int a = 1; a <= 1e4; a++) {
        for (auto &ans : res) {
            int b = n * a - ans;
            if (b >= 1 && b <= min(10000*1LL , n*a) && sz(to_string(n))*a - b == sz(to_string(ans))) {
                op.pb({a, b});
            }
        }
    }

    cout << sz(op) << endl;
    for (auto &it : op) {
        cout << it.ff << " " << it.ss << endl;
    }
}

// Main function
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
