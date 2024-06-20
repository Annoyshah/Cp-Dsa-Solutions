
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
    int workRem=0;
    for(auto &it : mp){
        // gap -- (mid-it.ss);
        // it.ff ke kitne units fill kr skte hai 
        // int q = (mid-it.ss);
       workRem+= (it.ss);
    }
    int workEachCanDo=0;
    for(int i=1 ; i<=n ; i++){
        if(tstamp[i]<mid) workEachCanDo += (mid - tstamp[i])/2;
    }
    if(workEachCanDo >= workRem) return true;
    }
    else{
        return(mid>=mp[1]);
    }

    
    return false;
}

void comderoP0612() {

int n,k;
cin>>n>>k;
vi v(k,0);
cin>>v;
map<int,int> mp;
for(int i=1 ; i<=n ; i++) mp[i]=0;
for(auto &it : v) mp[it]++;
// deb(v);
// n workers k tasks
// vector consists of indexes of workes profficient in task ai

// go for binary search ...
// approach ...preddicate function ..
// check for t=0 if tasks are posiible or not ...go on chekcing for t=1 , t=2 , t=3 , t=4 ..and so on 
// / will notice that for some point of time values will be false but after some point of time values will go on to be true ...
// this gives idea about binary search
// for dp there will be no such pattern ,  it will be false true false true oscillating and alternating patterns of false and true after certain intervals of time
// bs .. F F F T T T T T T  T T .....Predicate fucntion
// dp ...F F T T F F T F T F T T ....
int l = 0 ; int r = 2*k;
while(l+1<r){
    int mid = (l+r)/2;
    if(check(mid , n , k , mp)){
        r = mid;
    }
    else{
        l = mid;
    }

}
cout<<r<<endl;
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