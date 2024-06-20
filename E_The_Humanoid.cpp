
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

pii check_if_k_proper(string &s, int k)
{
    int idx1 = -1;
    int idx2 = -1;
    bool found = false;
    for (int i = 0; i < sz(s);)
    {
        char a = s[i];
        int parts = 1;
        for (; parts <= k - 1;)
        {
            if (a == s[i + parts])
                parts++;
            else
            {
                idx1 = i;
                idx2 = parts;
                found = true;
                break;
            }
        }
        i = (i + k);
        if (found)
            break;
    }
    return {idx1, idx2};
}
int f(int idx , int power , int b ,int g , vector<int>& vec){
    if(idx>=vec.size() ) return 0;

   if(power > vec[idx]){
     return 1 + f(idx+1 , power + vec[idx]/2 , b , g , vec);
   }
   int pick2  = b > 0 ? f(idx ,  power*2 , b-1 , g , vec) : 0;
   int pick3 = g > 0 ? f(idx , power*3, b , g-1 , vec ) : 0;
   return max(pick2 , pick3);
}

void comderoP0612()
{
    int n, p;
    cin >> n >> p;
    vector<int> vec(n, 0);
    cin >> vec;
    sort(vec.begin(), vec.end());
    cout<< f(0 , p , 2, 1 , vec) << "\n";
    // multiset<int> mset;
    // for (auto &it : vec)
    // {
    //     mset.insert(it);
    // }
    // int b = 1;
    // int g = 1;
    // while (sz(mset) > 0)
    // {
    //     auto it = mset.lower_bound(p);
    //     while (*it >= p && it != mset.begin())
    //         --it;
    //     if (*it < p)
    //     {
    //         p += (*it / 2);
    //         mset.erase(mset.find(*it));
    //     }
    //     else
    //     {
    //         if (b > 0 && g > 0)
    //         {
    //             int p1 = p;
    //             int p2 = p;
    //             p1 = p1 + 2 * p; // p1 is for g
    //             p2 = p2 + 3 * p;
    //             auto it1 = mset.lower_bound(p1);
    //             auto it2 = mset.lower_bound(p2);
    //             if (*it1 >= *it2)
    //             {
    //                 g -= 1;
    //                 p = p1;
    //                 continue;
    //             }
    //             else
    //             {
    //                 // blue ko lene do
    //                 b -= 1;
    //                 p = p2;
    //             }
    //         }
    //         else if(b > 0)
    //         {
    //           b-=1;
    //           p = p + 3*p;
    //         }
    //         else if( g > 0)
    //         {
    //             g-=1;
    //             p+=(2*p);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // cout<<n - mset.size()<<endl;


    // use reursion to solve the problem 

}
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
        comderoP0612();
    return 0;
}