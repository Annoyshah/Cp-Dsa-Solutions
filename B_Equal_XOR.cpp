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
int n,k;
cin>>n>>k;
vi v(n*2);
cin>>v;
map<int,int> mp1;
map<int,int> mp2;
set<int> st1;
set<int> st2;
int cnt1=0 , cnt2=0 ;
int cnt3=0;
for(int i=0 ; i<n ; i++){
    mp1[v[i]]++;
}
for(int i=n ; i<2*n ; i++){
    mp2[v[i]]++;
}
for(auto &it : mp1){
    if(it.ss==2 && cnt1<k){
        st1.insert(it.ff);
        cnt1++;
    }
   
}
for(auto &it : mp2){
    if(it.ss==2 && cnt2<k){
        st2.insert(it.ff);
        cnt2++;
    }
}
if(cnt1==k && cnt2==k){
    for(auto &it : st1){
        cout<<it<<" "<<it<<" ";
    }
    cout<<endl;
    for(auto &it : st2){
        cout<<it<<" "<<it<<" ";
    }
    cout<<endl;
    return;
}
vi vec;
for(auto &it: mp1){
     if(mp2[it.ff]>=1 && cnt3<2*k){
        if(cnt3==2*k) break;
       for(int i=0 ; i<it.ss ; i++){
        if(cnt3==2*k) break;
        vec.pb(it.ff);
        cnt3++;
       } 
       
        
    }
}
if(cnt3==2*k && vec.size()==2*k){
        for(auto &it: vec){
            cout<<it<<" ";
        }
        cout<<endl;
          for(auto &it: vec){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
else{
    int cn1=2*k ; int cn2=2*k;
    for(auto &it : st1){
        cout<<it<<" "<<it<<" ";
        cn1-=2;
    }
    for(auto &it: vec){
           if(cn1>0) cout<<it<<" ";
            cn1-=1;
        }
        cout<<endl;
    for(auto &it : st2){
        cout<<it<<" "<<it<<" ";
        cn2-=2;
    }
      for(auto &it: vec){
            if(cn2>0)cout<<it<<" ";
            cn2-=1;
        }
        cout<<endl;
        return;
}
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