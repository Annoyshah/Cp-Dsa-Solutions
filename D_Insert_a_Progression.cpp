
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

bool check(int mid, vector<vi> &pref, vector<int> &vec)
{
    int n = sz(vec);
    if (mid > n)
        return false;

    int q = mid - 1;
    int prev_or = 0;
    for (int j = 20; j >= 0; j--)
    {
        if (pref[q][j] > 0)
            prev_or |= (1 << j);
    }

    bool found = false;
    for (int i = 1; i + mid - 1 < n; i++)
    {
        int cur_or = 0;
        int k = i + mid - 1;
        for (int j = 20; j >= 0; j--)
        {
            if ((pref[k][j] - pref[i - 1][j]) > 0)
                cur_or |= (1 << j);
        }
        if (prev_or != cur_or)
        {
            found = true;
            break;
        }
    }
    return !found;
}
bool check_if_peak_max(vector<int> &p, vector<int> &q, int r)
{
    vi ans(sz(p), 0);
    bool found = false;
    for (int i = 0; i < sz(p); i++)
    {
        ans[i] = p[i] + q[i];
    }
    for (int i = 1 * r; i < sz(p) - 1; i += 2)
    {
        if (ans[i] > ans[i - 1] and ans[i] > ans[i + 1])
            continue;
        else
        {
            found = true;
            break;
        }
    }
    return !found;
}
int function_to_provide_minimum(set<int> &st, int first, int last)
{
    int score1 = 0;
    int prev1 = first;
    set<int> st1 = st;

    while (!st1.empty())
    {
        auto it = st1.lower_bound(prev1);
        auto it2 = (it == st1.begin()) ? st1.end() : prev(it);

        int score12 = (it == st1.end()) ? LLONG_MAX : abs(*it - prev1);
        int score10 = (it2 == st1.end()) ? LLONG_MAX : abs(*it2 - prev1);

        if (score12 < score10)
        {
            prev1 = *it;
            st1.erase(it);
        }
        else
        {
            prev1 = *it2;
            st1.erase(it2);
        }
        score1 += min(score12, score10);
    }

    int score2 = 0;
    int prev2 = last;
    set<int> st2 = st;

    while (!st2.empty())
    {
        auto it = st2.lower_bound(prev2);
        auto it2 = (it == st2.begin()) ? st2.end() : prev(it);

        int score20 = (it == st2.end()) ? LLONG_MAX : abs(*it - prev2);
        int score22 = (it2 == st2.end()) ? LLONG_MAX : abs(*it2 - prev2);

        if (score20 < score22)
        {
            prev2 = *it;
            st2.erase(it);
        }
        else
        {
            prev2 = *it2;
            st2.erase(it2);
        }
        score2 += min(score20, score22);
    }
    /// agar abhi bhi koi range me ho to daldena

    return min(score1, score2);
}

void comderoP0612()
{
    int n, x;
    cin >> n >> x;
    vi vec(n);
    cin >> vec;

    int cnt = 0;
    int score = 0;
    for (int i = 0; i < n - 1; i++)
    {
        score += abs(vec[i] - vec[i + 1]);
    }
    int mini = *min_element(all(vec));
    int maxi = *max_element(all(vec));
    int segleft = 0;
    int segright = 0;
    if (mini > 1)
    {
        segleft = min(2 * (mini - 1) , min(vec[0] , vec[n-1])-1);
    }
    if (x > maxi)
    {
        segright = min(2 * (x - maxi) , x-max(vec[0] , vec[n-1]));
    }
    score += min({segleft + segright});

    cout << score << endl;
}
int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        comderoP0612();
    return 0;
}