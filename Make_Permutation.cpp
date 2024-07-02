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
#define pii pair<int, int>
#define vi vector<int>
#define repL(i, a, b) for (int i = (a); i < (b); i++)

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int tc = 1;

bool isValidNumber(int num, int size, const vector<int>& used) {
    return num >= 1 && num <= size && !used[num];
}

bool placeNumber(int index, int size, const vector<int>& arr, vector<int>& usedFlags) {
    for (int diff = 0; diff <= size; ++diff) {
        int possibleNumber = arr[index] + diff;
        if (isValidNumber(possibleNumber, size, usedFlags)) {
            usedFlags[possibleNumber] = 1;
            return true;
        }
    }
    return false;
}

bool canBePermutation(int size, const vector<int>& vecu) {
    vector<int> usedFlags(size + 1, 0);

    for (int index = 0; index < size; ++index) {
        if (!placeNumber(index, size, vecu, usedFlags)) {
            return false;
        }
    }
    return true;
}

void comderoP0612() {
    int n;
    cin >> n;
    vector<int> vec(n,0);
    cin >> vec;

    if (canBePermutation(n,vec)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
