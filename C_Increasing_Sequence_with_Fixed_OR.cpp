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
void comderoP0612(){
 int n;
 cin>>n;
 if(n==1){
    cout<<1<<endl;
    cout<<1<<endl;
    return;
 }
 if(n==2){
    cout<<1<<endl;
    cout<<2<<endl;
    return;
 }
 vi num(64,0);
 int cnt=0;
 for(int bits=63 ; bits>=0 ; bits--){
    int bit = (n>>bits)&1;
    if(bit==1) cnt++;
    num[63-bits] = bit;
 }
//  deb(num);
//  deb(num);
//  int cnt = __builtin_popcountl(n);
//  deb(cnt);
 int k = 1;
 int prev=n;
 vi res;
 res.pb(prev);
//  110111100000101101101011001110100111011001000000000000000000
 while(k!=(cnt+1)){
    int ans=0;
    int count=0;
    int ind=0;
    for(int idx=63 ; idx>=0 ; idx--){
        if(num[idx]==1){
            count++;
        }
        if(count==k){
            //idhar tak ka number swapped hoga
            ind=idx;
            break;
        }
    }
    // deb(ind);
    for(int i=0 ; i<ind ; i++){
        // deb(i);
        if(num[i]==1){
            ans |= (1LL<<(63-i));
            // deb(ans);
        }
    }
    // deb(ans);
    for(int i=ind ; i<=63 ; i++){
        if(num[i]==1){
             int bit = ((prev>>(63-i))&1);
             bit^=1;
             ans |= (bit<<(63-i));
        }
    }
    // deb(ans);
    if(ans>0)res.pb(ans);
    prev = ans;
    k++;
 }
cout<<sz(res)<<endl;
sort(all(res));
cout<<res<<endl;
}
// Brute force code I coded to study the pattern used for the question , take valuwe of num as 25,31,23,14 you will get the pattern 
// ******************************************************************************/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int num=25;
//     vector<int> vec;
//   int cnt=5;
//   int prev = 0;
//   while(cnt--){
//     for(int i=1 ; i<=25 ; i++){
//         vec.push_back(i);
//         prev = i;
//         for(int j=i+1 ; j<=25 ; j++){
//             if((prev|j)==num){
//                 vec.push_back(j);
//                 prev = j;
//                 continue;
//             }
//         }
//            for(auto &it : vec){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     vec.clear();
//     }
 
//   }

//     return 0;
// }
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