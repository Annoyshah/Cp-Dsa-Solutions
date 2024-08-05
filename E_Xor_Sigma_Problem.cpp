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

long long calculateXORSums(int N, const vector<int>& A) {
    vector<int> prefix_xor(N + 1, 0);
    unordered_map<int, int> xor_count;
    long long result = 0;

    for (int i = 1; i <= N; ++i) {
        prefix_xor[i] = prefix_xor[i - 1] ^ A[i - 1];
    }

    for (int i = 0; i <= N; ++i) {
        result += xor_count[prefix_xor[i]];
        xor_count[prefix_xor[i]]++;
    }

    return result;
}

void comderoP0612() {
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;

    vector<vector<int>> pref(n, vector<int>(64, 0));
    for (int bits = 63; bits >= 0; bits--) {
        int bit = (vec[0] >> bits) & 1;
        pref[0][63 - bits] = bit;
    }
    for (int i = 1; i < n; i++) {
        for (int bits = 63; bits >= 0; bits--) {
            int bit = (vec[i] >> bits) & 1;
            pref[i][63 - bits] = pref[i - 1][63 - bits] + bit;
        }
    }

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        int ans = 0;
        for (int j = 0; j <= 63; j++) {
            int total = n - 1 - (i + 1) + 1;
            int ones = pref[n - 1][j] -  pref[i][j];
            int zeroes = total - ones;
            if (ones == zeroes) {
            } else if (ones > zeroes) {
                // 
                if(ones %2 !=0){
                    ans |= 1LL << (63 - j);
                }
            } else {
                
                if(ones %2 !=0){
                    ans |= 1LL << (63 - j);
                }
            }
        }
        total += ans;
    }
    cout << total << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    comderoP0612();
    return 0;
}
