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
void comderoP0612()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vi vec(n, 0);
    cin >> vec;
    vector<pii> v;
    for (int i = 0; i < n; i++)
    {
        v.pb({vec[i], i + 1});
    }
    sort(allr(v));
    // deb(v);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({v[i].ff, v[i].ss});
    }
    if (s1 > s2 || s2 > s1)
    {
        int aend = 0;
        int bend = 0;
        vi lista;
        vi listb;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            bend += s2;
            aend += s1;
            if (bend < aend)
            {
                listb.pb(x.ss);
                aend -= s1;
            }
            else if (bend > aend)
            {
                lista.pb(x.ss);
                bend -= s2;
            }
            else
            {
                if (!pq.empty())
                {
                    auto q = pq.top();
                    pq.pop();
                    if (s1 > s2)
                        lista.pb(q.ss);
                    else
                        listb.pb(q.ss);
                }
                if (s1 > s2)
                    listb.pb(x.ss);
                else
                    lista.pb(x.ss);
            }
        }
        // deb(lista);
        // deb(listb);
        cout << sz(lista) << " ";
        for (int i = 0; i < sz(lista); i++)
        {
            cout << lista[i] << " ";
        }
        cout << endl;
        cout << sz(listb) << " ";
        for (int i = 0; i < sz(listb); i++)
        {
            cout << listb[i] << " ";
        }
        cout << endl;
    }
    else
    {
        vi lista;
        vi listb;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            lista.pb(x.ss);
            if (!pq.empty())
            {
                auto y = pq.top();
                pq.pop();
                listb.pb(y.ss);
            }
        }
        cout << sz(lista) << " ";
        for (int i = 0; i < sz(lista); i++)
        {
            cout << lista[i] << " ";
        }
        cout << endl;
        cout << sz(listb) << " ";
        for (int i = 0; i < sz(listb); i++)
        {
            cout << listb[i] << " ";
        }
        cout << endl;
    }
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