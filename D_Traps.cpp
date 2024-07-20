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

 
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
// i thought this dp will work but it won't 
    // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    // int jumpstillnow = 0;
    // deb(n);
    // deb(k);
    // function<int(int, int)> f = [&](int idx, int flag) -> int {
    //     if (idx >= sz(vec)) return 0;
    //     deb(idx);
    //     // deb(flag);
    //     if (dp[idx][flag] != -1) return dp[idx][flag];
        
      
    //     if (flag) jumpstillnow++;
    //     // deb(jumpstillnow);
    //     int take = (vec[idx] + jumpstillnow) + f(idx + 1, 0);
    //     int not_take = LLONG_MAX;
    //     if(jumpstillnow < k ) not_take = f(idx + 1, 1);
    //     deb(take);
    //     deb(not_take);
    //     return dp[idx][flag] = min(take, not_take);
    // };
    
    // int result = f(0, 0);
    // cout << result << endl;




       // dekho mere bhai
    // har skip ke baad ai +1 se hi badhega matlab 3 skip ke baad ai -> ai+3 ho chuka hoga pr agar aap sirf added cost to total dekhoge to ai ke aage bache hue elements me +1 hi ho rha hoga har skip ke baad
    // seedhe baat hai
    // total cost / total damage = a1+a2+a3+a4...+ai+ai+1+....an
    // if i choose to skip at any index i , i will remove ai from the total cost and add +1 to all elements after ai , i.e
    // I will add +1 to n-i elements 
    // so totaldamage will become totaldamage = totaldamage - ai + n-i
    // now you will argue that at any index after ai , lets say ai+3 we choose to skip this i+3 index then 
    // I need to skip this also so the +1 which i adde dfor this i+3rd index when i removed ai will not be considered
    // so if i skip 2 elements after skipping ai then i will be having n-i-2 added to the total damage not n-i
    // a1 , a2 , a3...ai , ai+1 , ...ai+2 ,... aj....ap....an
    // at ai
    // ai - ( n - i ) + k-1...k-1 are the traps to come after removing ai so only n-i-(k-1) will be added to toltal damage so ai - (n-i) + (k-1) will be removed to the total cost
    // aj - (n-j) + (k-2) .. k-2 remaining traps
    // ak - (n-k) + (k-3) 


    // k-1 + k-2 + k-3.....ye poora extra factor hai ... iska sum k*(k-1)/2;
    // baaki bacha ai - (n-i) + aj - (n-j) + ak - (n-k) ki max value as ye remove dcost hai
    
void comderoP0612() {
    int n, k;
    cin >> n >> k;
    vi vec(n);
    cin >> vec;

    int total_damage = accumulate(all(vec), 0LL); // calculate total damage
    vi removed;

    for (int i = 0; i < n; i++) {
        int remove = vec[i] - (n - 1 - i);
        removed.pb(remove);
    }

    sort(allr(removed)); // sort the removal costs in descending order

    for (int i = 0; i < k; i++) {
        total_damage -= removed[i];
    }

    int extra = (k * (k - 1)) / 2;
    total_damage -= extra;

    cout << total_damage << endl;
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