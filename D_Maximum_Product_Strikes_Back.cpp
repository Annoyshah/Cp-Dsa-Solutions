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

void compderoP0612()
{
    int n;
    cin >> n;
    vi v(n, 0);
    cin >> v;
    deb(v);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }
    bool foundzero = false;
    bool foundoddnegatives = false;
    int mul = 1;
    int cnt = 0;
    for (auto &it : mp)
    {
        if (it.ff == 0)
        {
            foundzero = true;
            continue;
        }
        if (it.ff < 0)
        {
            cnt += it.ss;
            continue;
        }
    }
    if (cnt % 2 != 0)
    {
        foundoddnegatives = 1;
    }

    set<pair<pair<int, int>, int>> st;
    if (foundzero)
    {
        int k = 0;
        int nefirst = 0;
        while (k < n and v[k] != 0)
        {
            if (v[k] < 0)
                nefirst++;
            k++;
        }
        int p = n - 1, neglast = 0;
        while (p >= 0 and v[p] != 0)
        {
            if (v[p] < 0)
                neglast++;
            p--;
        }
        if (k < n and v[k] == 0)
            st.insert({{0, k}, nefirst});
        if (p >= 0 and v[p] == 0)
            st.insert({{p, n - 1}, neglast});
        int i = 0;
        for (; i < n;)
        {
            int j = i + 1;
            if (v[i] == 0)
            {
                int negatives = 0;
                while (j < n and v[j] != 0)
                {
                    if (v[j] < 0)
                        negatives++;
                    j++;
                }
                if (j < n and v[j] == 0)
                {
                    st.insert({{i, j}, negatives});
                }
            }
            i = j;
        }
    }
    if (sz(st) > 0)
    {
        for (auto &it : st)
        {
            cout << it.ff.ff << " " << it.ff.ss << " " << it.ss << endl;
        }
    }
    else
    {
        // move to positins closest to first negative numbers

        if (v[0] > 0 and v[n - 1] > 0)
        {

            int i = 0;
            int j = n - 1;
            int firstmul = 1;
            while (i < n and v[i] > 0)
            {
                firstmul *= v[i];
                i++;
            }
            int lastmul = 1;
            while (j >= 0 and v[j] > 0)
            {
                lastmul *= 1;
                j--;
            }
            if (firstmul >= lastmul)
            {
                cout << 0 << " " << n - j << endl;
                return;
            }
            else
            {
                cout << i << " " << 0 << endl;
                return;
            }
        }
        else if (v[0] * v[n - 1] < 0)
        {
            int leftmul = 1;
            int rightmul = 1;
            int i = 0;
            int j = n - 1;
            while (i < n and v[i] > 0)
            {
                leftmul *= abs(v[i]);
                i++;
            }
            while (j >= 0 and v[j] > 0)
            {
                rightmul *= abs(v[j]);
                j--;
            }
            if(i!=j){
            leftmul*=abs(v[i]);
            rightmul*=abs(v[j]);
            }
            if (leftmul >= rightmul)
            {
                cout << 0 << " " << n - j << endl;
                return;
            }
            else
            {
                cout << i << " " << 0 << endl;
                return;
            }
        }
        else if (v[0] < 0 and v[n - 1] < 0)
        {
            int leftmul = abs(v[0]);
            int rightmul = abs(v[n-1]);
            int i = 0;
            int j = n - 1;
            if (leftmul >= rightmul)
            {
                cout << 0 << " " << n - j << endl;
                return;
            }
            else
            {
                cout << 1 << " " << 0 << endl;
                return;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        compderoP0612();
    }
    return 0;
}
