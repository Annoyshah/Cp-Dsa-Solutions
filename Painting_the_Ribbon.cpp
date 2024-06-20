
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
int tt=1;

bool check(int mid , int n , int k , map<int,int> mp){
    // deb(mid);
    if(n>1){
        vi tstamp(n+1,0);
    for(auto &it : mp){
        // deb(it.ss);
        if(it.ss >= mid ){
            it.ss-=mid;
            tstamp[it.ff] = (mid);
        }
        else{
            
            tstamp[it.ff] = (it.ss);
            it.ss=0;
        }
    }
    int sum=0;
    for(auto &it : mp){
       sum+= (2*it.ss);
    }
    // deb(sum);
    for(int i=1 ; i<=n ; i++){
        // deb(i);
        // deb(tstamp[i]);
        // deb(sum);
        if(tstamp[i]<mid and sum + tstamp[i] >= mid) sum-=(mid - tstamp[i]);
        else if(tstamp[i]<mid and sum + tstamp[i]<=mid) sum = 0;
    }
    if(sum == 0 && tstamp[n]<=mid) return true;
    }
    else{
        return(mid>=mp[1]);
    }
    // deb(sum);
    
    return false;
}
//jcext cext cet ce c
void find(vi& cnt , string& s ){
    // deb(s);
    int last=-1;
    for(int i=0 ; i<sz(cnt) ; i++){
        if(cnt[i]>0) last = i;
    }
    // deb(last);
    if(last!=-1 && last<=26){
    cnt[last]--;
   int idx = -1;
   for(int i=0 ; i<sz(s) ; i++){
    if(s[i]==(last + 'a')){
        idx = i;
        break;
    }
   }
//    deb(idx);
   if(idx>-1 & idx<sz(s))s.erase(s.begin() + idx);
}
}
void comderoP0612() {
    int n,m,k;
    cin>>n>>m>>k;
if(n-(n/m + (n%m!=0))<=k) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
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