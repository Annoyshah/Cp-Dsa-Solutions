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
#define INF LLONG_MAX
#define NINF LLONG_MIN

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int tc = 1;
int countMatchingSubstrings(const string &a, const string &b) {
    int n = a.size();
    int totalSubstrings = 0;
    int consecutiveMatches = 0;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            consecutiveMatches++;
        } else {
            // Calculate the number of substrings for the current segment of matches
            totalSubstrings += (consecutiveMatches * (consecutiveMatches + 1)) / 2;
            consecutiveMatches = 0;
        }
    }
    // Add the last segment if it ended at the end of the string
    totalSubstrings += (consecutiveMatches * (consecutiveMatches + 1)) / 2;
    
    return totalSubstrings;
}
void compderoP0612()
{
int n;
cin>>n;
vi v(n+1,0);
for(int i=1 ; i<=n ; i++) cin>>v[i];
vi dp(n+1 , 0);
dp[0] = 1;
for(int i=1 ;i<=n ; i++){

    // if seg is to left 
    if(i-(v[i]+1)>=0 and dp[i-(v[i]+1)]){
        dp[i] = 1;
    }
    // if segment is to right 
    // if(dp[i]==1) means that v[i] size of segment exists to either left or right and all the segemnts beforehand are valid segments
    if(i+(v[i])<=n and dp[i-1]==1){
        dp[i+v[i]] = 1;
    }
}
// deb(dp);
if(dp[n]){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

}
// 3 1
// abc    // a b d
// abd    // a b 

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
