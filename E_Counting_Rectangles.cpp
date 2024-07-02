/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */
#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }

#define int long long
#define ll long long
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

int toggleKthBit(unsigned long long num, int k) {
    // Create a bitmask with the k-th bit set
    unsigned long long bitmask = 1ULL << k;

    // Toggle the k-th bit using XOR
    return num ^ bitmask;
}
struct CompareFirst {
    bool operator()(const pii &a, const pii &b) const {
        return a.ff < b.ff;
    }
};
void comderoP0612() {
    long long n, q;
    cin >> n >> q;
    
    vector<vector<long long>> pref(1001, vector<long long>(1001, 0));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pref[x][y] += x * y;
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }

    for (int j = 1; j <= 1000; j++) {
        for (int i = 1; i <= 1000; i++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        
        long long ans = pref[hb-1][wb-1]-pref[hs][wb-1]-pref[hb-1][ws]+pref[hs][ws];
        cout << ans << endl;
    }
}


int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}