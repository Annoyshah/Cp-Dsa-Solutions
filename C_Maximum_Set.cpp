
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
    int l,r; cin>>l>>r;
    int curr=l,lvl=1;
    while(curr*2LL<=r)
    {
        curr*=2LL;
        lvl++;
    }
    curr/=l;
    int end1=r/curr;
    curr/=2;
    int ans=0;
    if(curr>0)
    {
        int end2=r/(curr*3LL);
        int indexes=end2-l+1;
        if(indexes>0)
        {
            ans=(indexes*(lvl-1))%mod;
            // deb(ans);
        }
    }
    ans=(ans+end1-l+1)%mod2;
    cout<<lvl<<" "<<ans<<endl;
    // deb(l) ; 
    // deb(r) ;
    // we have min l 
    // l<=x<=r
    // but i will have series of x , 2*x , 2^2*x , 2^3*x ...2^(k-1)*x
    // 2^(k-1)*x <= r;
    // x <= r/2^(k-1);
    // int peak = 1 ; int k = 1;
    // while(peak*2 <= r){
    //     k++;    
    //     peak*=2;
        
    // }
    // deb(peak);
    // // peak/=1;
    // int ans = r/peak - l + 1 ; // b - a +1 numbers betweeen l and r/2^(k-1)*x
    // // same foes for 3 series also but its better to use thrice 2*2*2 factor than 3*3 twice 3 factor as 2*2*2 is 8 and 3*3=9 , so if we take 8 resulting value will be smaller and we will bw able to add more ele to our set
    // // series will be x , 3*x , 3*2*x , 3*2^2*x ....2^(k-2)*3*x , 2^(k-2)*3 <= r
    // //  r/2^(k-2)*3 => peak/2 * 3
    // // 3 2 2 2 , 2 2 2 3 , any permutation of oredre of multiplication is valid so it will be (k-1)!/(k-2)!
    // peak/=2;
    // peak*=3;
    // ans +=  max(0LL , (r/peak - l + 1)*(k-1));        

    // cout<<k <<" "<<ans<<endl;
    
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}