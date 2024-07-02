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
// Find position of MSB in n. For example if n = 17,
// then position of MSB is 4. If n = 7, value of MSB
// is 2
int msbPos(ll n)
{
    int msb_p = -1;
    while (n)
    {
        n = n >> 1LL;
        msb_p++;
    }
    return msb_p;
}

// Function to find Bit-wise & of all numbers from x
// to y.
ll andOperator(ll x, ll y)
{
    ll res = 0; // Initialize result

    while (x && y)
    {
        // Find positions of MSB in x and y
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);

        // If positions are not same, return
        if (msb_p1 != msb_p2)
            break;

        // Add 2^msb_p1 to result
        ll msb_val = (1LL << msb_p1);
        res = res + msb_val;

        // subtract 2^msb_p1 from x and y.
        x = x - msb_val;
        y = y - msb_val;
    }

    return res;
}
void comderoP0612()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> mp;
    set<char> st;
    // grouping of 1 , 2 , 3, 4, 5, ..n
    for (auto &it : s)
    {
        mp[it]++;
    }
    int mingrp = INT_MAX;
    int minopr = INT_MAX;
    for (int grp = 1; grp <= n; grp++)
    {
        if (n % grp == 0)
        {
            int cnt = 0;
            int opr = 0;
            for (auto &it : mp)
            {
                if (cnt < n)
                {
                    if (it.ss == grp)
                    {
                        cnt += (grp);
                        continue;
                    }
                    else
                    {
                        if (it.ss > grp)
                        {
                            opr += (it.ss - grp);
                            cnt += (grp);
                        }
                        else
                        {
                            opr += (grp - it.ss);
                            cnt += (grp);
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
            if (opr < minopr)
            {
                minopr = opr;
                mingrp = grp;
            }
            else
            {
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    cout<<minopr<<endl;
    string str = s;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> minH;
    for (auto &it : mp)
    {
        minH.push({abs(it.ss - mingrp), it.ff});
        //  minopr-=abs(it.ss-mingrp);
    }
    map<int, int> mp2 = mp;
    int cnt = 0;
    while (!minH.empty())
    {
        auto top = minH.top();
        minH.pop();
        if (cnt < n and minopr > 0)
        {
            minopr -= top.first;
            for (auto &it : mp)
            {
                if (it.ff == top.ss)
                {
                    it.ss = mingrp;
                }
            }
            cnt += mingrp;
        }
        else
        {
            break;
        }
    }
    set<int> nikalo;
    for (auto &it : mp)
    {
        if (it.ss != mingrp)
        {
            nikalo.insert(it.ff);
        }
    }
    // for (auto &it : nikalo)
    //     cout << (char)it << " ";
    for (int ch = 'a'; ch <= 'z'; ch++)
        if (mp2.find(ch) == mp2.end())
            st.insert(ch);


    for (auto &it : mp)
    {
        if (nikalo.find(it.ff) == nikalo.end())
        {
            if (it.ss > mp2[it.ff])
            {
                int cnt = it.ss - mp2[it.ff];

                for (int i = 0; i < sz(str); i++)
                {
                    if (cnt > 0)
                    {
                        if (nikalo.find(str[i]) != nikalo.end() and mp2[str[i]] != 0)
                        {
                            mp2[str[i]] -= 1;
                            str[i] = it.ff;
                            cnt -= 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
              
            }
            else if (it.ss < mp2[it.ff])
            {
                int remove = mp2[it.ff] - it.ss;
                for (int i = 0; i < sz(str); i++)
                {
                    if (remove > 0)
                    {
                        if (str[i] == it.ff)
                        {
                            str[i] = *st.begin();
                            auto it = st.begin();
                            st.erase(it);
                            remove--;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                
            }
        }
        else{
            continue;
        }
    }
    cout << str << endl;
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
