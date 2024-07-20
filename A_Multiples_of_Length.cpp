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
    vi vec(n,0);
    cin>>vec;
    // make first number multiple of 1...i.e if first number is a
    // make it -a
    if(sz(vec) > 2){
    cout<<1<<" "<<1<<endl;
    cout<<-vec[0]<<endl;
    int len = n-1;
    cout<<2<<" "<<n<<endl;
    vi opr2;
    for(int i=1 ; i<n ; i++){
        opr2.pb(vec[i]*len);
    }
    for(int i=0 ; i<sz(opr2) ; i++){
        cout<<opr2[i]<<" ";
    }
    cout<<endl;
    cout<<1<<" "<<n<<endl;
    vi opr3;
    for(int i=0 ; i<n ; i++){
       if(i>0) opr3.pb(-vec[i]*(len+1));
       else opr3.pb(0);
    }
    for(int i=0;i<sz(opr3); i++){
        cout<<opr3[i]<<" ";
    }
    cout<<endl;
    }
    else if(sz(vec)==1){
    cout<<1<<" "<<1<<endl;
    cout<<-vec[0]<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<0<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<0<<endl;
    }
    else{
    cout<<1<<" "<<1<<endl;
    cout<<-vec[0]<<endl;
    cout<<2<<" "<<2<<endl;
    cout<<-vec[1]<<endl;
    cout<<2<<" "<<2<<endl;
    cout<<0<<endl;
    }

}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    comderoP0612();
    return 0;
}