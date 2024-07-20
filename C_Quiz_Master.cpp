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

vector<vector<int>> factors(100001);

void precomputeFactors() {
    for (int i = 1; i <= 100000; i++) {
        for (int j = i; j <= 100000; j += i) {
            factors[j].push_back(i);
        }
    }
}
//implementation using 2 pointers 
// i can get factors in O(1e5 * log base 2(1e5)) which can go upto 10^5 * log2(10^5)
// funda : if a number can be expressed in x^a * y ^b * z^c then its factors will be (a+1)(b+1)(c+1)
// num = 10^5 = (2^5 * 5^5) so factors will be 36 only
// so by 2pointers / sliding window i will travese to segments of i to j and check which first i->j segement covers all m topic (i.e which segemnts has all factors covered in 1 to m)
// from i I get a segement at a particular j , I will increase my i and remove contribution i and move from i+1 and the right pointer moves from j to ahead as if my i to j-1(i to j has covered) has not covered all 1 to  topics how will i+1 to j-1 will cover so from i+1 we need atleast segment till j to cover all 1 to m topics
// first time i visit a topic then i increase a count and increase unique count , unquie tells that if all m topics has been covered or not

void comderoP0612() {
    int n, m;
    cin >> n >> m;
    vi vec(n, 0);
    cin >> vec;
    sort(all(vec));
    vi vis(m + 1, 0);
    // sliding window / 2 pointers krke i ka contribution hataunga matlab i jo bhi factors cover kr rha tha unko hata dunga unuique count aur visited dono se
    // upar dekho j aage badh gya hoga curr segment length jahan pe m topics cover hue waha se issliye vec[j-1] - vec[i] kiya hai koi chukne 
    int min_ans = 1e6;
    int unique = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && unique < m) {
            for (auto &it : factors[vec[j]]) {
                if (it > m) break;
                if (it > 0) {
                    vis[it]++;
                    if (vis[it] == 1) unique++;
                }
            }
            j++;
        }
        if (unique == m) {
            min_ans = min(min_ans, vec[j - 1] - vec[i]);
        }
        for (auto &it : factors[vec[i]]) {
            if (it > m) break;
            if (it > 0 && vis[it] > 0) {
                vis[it]--;
                if (vis[it] == 0) unique--;
            }
        }
    }
    if (min_ans == 1e6) {
        cout << -1 << endl;
    } else {
        cout << min_ans << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    precomputeFactors();
    while (t--) comderoP0612();
    return 0;
}
