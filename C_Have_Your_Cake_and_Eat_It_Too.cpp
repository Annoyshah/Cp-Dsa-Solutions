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
    in >> p.first >> p.second;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
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

void findSegments(int num, vector<int> &vec, map<int, vector<pii>> &mp, int target)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int n = vec.size();
    while (j < n)
    {
        sum += vec[j];
        while ((i < n && j < n) && sum >= target)
        {
            if (i <= j && i >= 0 && j >= 0 && i < n && j < n)
            {
                mp[num].pb({i, j});
            }
            sum -= vec[i];
            i++;
        }
        j++;
    }
}

void comderoP0612()
{
    int n;
    cin >> n;
    vi v1(n, 0);
    cin >> v1;
    vi v2(n, 0);
    cin >> v2;
    vi v3(n, 0);
    cin >> v3;
    vector<pair<int, pii>> res;
    map<int, vector<pair<int, int>>> mp;
    int sum1 = accumulate(all(v1), 0LL);
    int sum2 = accumulate(all(v2), 0LL);
    int sum3 = accumulate(all(v3), 0LL);
    findSegments(1, v1, mp, ((sum1 + 2) / 3));
    findSegments(2, v2, mp, ((sum2 + 2) / 3));
    findSegments(3, v3, mp, ((sum3 + 2) / 3));
    bool found = false;
    vector<vector<pii>> num(4);
    num[1] = {{2, 3}, {3, 2}};
    num[2] = {{1, 3}, {3, 1}};
    num[3] = {{1, 2}, {2, 1}};
    for (int i = 1; i <= 3; i++)
    {
        sort(all(mp[i]));
    }
    for (int i = 1; i <= 3; i++)
    {
        if (found) break;
        for (auto &it : mp[i])
        {
            if (found) break;
            int l = it.ff;
            int r = it.ss;
            for (auto &options : num[i])
            {
                int option1 = options.ff;
                int option2 = options.ss;
                auto it1 = upper_bound(mp[option1].begin(), mp[option1].end(), make_pair(r, 0),
                                       [](const pair<int, int> &a, const pair<int, int> &b)
                                       {
                                           return a.first < b.first;
                                       });
                if (it1 != mp[option1].end() and (it1->first>=0 and it1->second<n))
                {
                    auto it2 = upper_bound(mp[option2].begin(), mp[option2].end(), make_pair(it1->second , 0),
                                           [](const pair<int, int> &a, const pair<int, int> &b)
                                           {
                                               return a.first < b.first;
                                           });
                    if (it2 != mp[option2].end() && (it2->first > it1->second) && (it1->second > r))
                    {
                        found = true;
                        res.pb({i, {l, r}});
                        res.pb({option1, {it1->first, it1->second}});
                        res.pb({option2, {it2->first, it2->second}});
                        break;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }
    if (!found)
    {
        cout << -1 << " ";
    }
    else
    {
        sort(all(res));
        for (auto &it : res)
        {
            cout << it.ss.ff + 1 << " " << it.ss.ss + 1 << " ";
        }
    }
    cout << endl;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--)
        comderoP0612();
    return 0;
}