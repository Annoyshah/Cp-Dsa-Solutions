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
#define pii pair<long long, long long>
#define vi vector<int>
#define repL(i, a, b) for (int i = (a); i < (b); i++)
#define INF LLONG_MAX
#define NINF LLONG_MIN

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int tc = 1;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE1 = 31;
const int BASE2 = 37;

pair<long long, long long> computeDoubleHash(const string &s) {
    long long hash1 = 0;
    long long hash2 = 0;
    long long power1 = 1;
    long long power2 = 1;

    for (char c : s) {
        hash1 = (hash1 + (c - 'A' + 1) * power1) % MOD1;
        hash2 = (hash2 + (c - 'A' + 1) * power2) % MOD2;
        power1 = (power1 * BASE1) % MOD1;
        power2 = (power2 * BASE2) % MOD2;
    }

    return {hash1, hash2};
}

vector<pii> power;

void precomputePowers(int n) {
    power.resize(n + 1);
    power[0] = {1, 1};
    for (int i = 1; i <= n; ++i) {
        power[i].first = (power[i - 1].first * BASE1) % MOD1;
        power[i].second = (power[i - 1].second * BASE2) % MOD2;
    }
}

pii getHash(int l, int r, const vector<pii>& prefixHash) {
    if (l == 0) {
        return prefixHash[r];
    }
    pii result;
    result.first = (prefixHash[r].first - (prefixHash[l - 1].first * power[r - l + 1].first) % MOD1 + MOD1) % MOD1;
    result.second = (prefixHash[r].second - (prefixHash[l - 1].second * power[r - l + 1].second) % MOD2 + MOD2) % MOD2;
    return result;
}

void compderoP0612() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    precomputePowers(n);
    
    set<pii> st;
    vector<pii> prefixHash(n);
    prefixHash[0] = computeDoubleHash(string(1, s[0]));
    
    for (int i = 1; i < n; ++i) {
        prefixHash[i].first = (prefixHash[i - 1].first * BASE1 + (s[i] - 'A' + 1)) % MOD1;
        prefixHash[i].second = (prefixHash[i - 1].second * BASE2 + (s[i] - 'A' + 1)) % MOD2;
    }

    for (int i = 0; i < n - 2; ++i) {
        if (s.substr(i, 3) == "ABA") {
            pii hashPrev = (i > 0) ? getHash(0, i - 1, prefixHash) : make_pair(0LL, 0LL);
            pii hashAfter = (i + 3 < n) ? getHash(i + 3, n - 1, prefixHash) : make_pair(0LL, 0LL);
            pii combinedHash = {
                (hashPrev.first * power[n - (i + 3)].first + hashAfter.first) % MOD1,
                (hashPrev.second * power[n - (i + 3)].second + hashAfter.second) % MOD2
            };
            st.insert(combinedHash);
        }
        if (s.substr(i, 3) == "BAB") {
            pii hashPrev = (i > 0) ? getHash(0, i - 1, prefixHash) : make_pair(0LL, 0LL);
            pii hashAfter = (i + 3 < n) ? getHash(i + 3, n - 1, prefixHash) : make_pair(0LL, 0LL);
            pii combinedHash = {
                (hashPrev.first * power[n - (i + 3)].first + hashAfter.first) % MOD1,
                (hashPrev.second * power[n - (i + 3)].second + hashAfter.second) % MOD2
            };
            st.insert(combinedHash);
        }
    }

    st.insert(computeDoubleHash(s));

    cout << sz(st) % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    compderoP0612();
    
    return 0;
}
