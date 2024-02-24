/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }
 
#define int long long int
#define ll int
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

int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;



const int N = 200000;
int n, k;
int a[N+5], h[N+5], pref[N+5], length[N+5];
bool get(int dist)
{
    bool found = false;
    for(int i = 0; i < n-dist+1; i++)
    {
        if(length[i] < dist){continue;}
        int sum = pref[i+dist]-pref[i];
        if(sum <= k)
        {
            found = true;
            break;
        }
    }
    return found;
}

void comderoP0612(){
pref[0] = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i+1] = pref[i]+a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    length[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
    {
        if(h[i]%h[i+1] == 0)
        {
            length[i] = length[i+1]+1;
        }
        else
        {
            length[i] = 1;
        }
    }
    int l = 1, r = N;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(get(mid))
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << r << endl;
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) comderoP0612();
    return 0;
}