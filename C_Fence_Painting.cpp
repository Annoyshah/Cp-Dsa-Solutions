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
void comderoP0612() {
    int n, m;
    cin >> n >> m;
    
    vi vec(n);
    cin >> vec;
    
    vi naya(n);
    cin >> naya;
    
    vi colors(m);
    cin >> colors;

    

   
     map<int,vi> mp4;
    for(int i=0 ; i<m ; i++){
        mp4[colors[i]].pb(i);
    }

    map<int,vi> mp2;
      map<int,vi> mp;
   
    for(int i=0 ;i<n ; i++){
        if(naya[i]!=vec[i]){
            mp2[naya[i]].pb(i);
        }
        mp[naya[i]].pb(i);

    }
   bool found =  false;
   for(int i=0 ; i<n ; i++){
    if(naya[i]==colors[m-1]){
        found = true;
        break;
    }
   }
   if(found){
    bool sad =  false;
     for(auto &it : mp2){
        if(mp4[it.ff].size()>=it.ss.size()) continue;
        else sad = true;
     }
     if(!sad){
        cout<<"YES"<<endl;
        vi res(m,-1);
        for(auto &it : mp2){
            int num = it.ss.size();
          if(mp4.find(it.ff)!=mp4.end()){
                for(int i=0  ; i<mp4[it.ff].size() ; i++){
                if(num==0) break;
                    res[mp4[it.ff][i]] = it.ss.back();
                    it.ss.pop_back();
                    num--;
            }
          }
        }
        // deb(res);
        for(int i=0 ; i<m ; i++){
            if(res[i]==-1 and mp.find(colors[i])!=mp.end()){
                res[i] = mp[colors[i]].back();
                // mp[colors[i]].pop_back();
            }
        }
        // deb(res);
        for(int i=0 ; i<m ; i++){
            if(res[i]>=0){
                int num = res[i];
                int idx = i-1;
                while(idx>=0 and res[idx]==-1){
                    res[idx] = num;
                    idx--;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            cout<<res[i]+1<<" ";
        }
    cout<<endl;
    return;
     }
     else{
        cout<<"NO"<<endl;
        return;
     }
   }else{
    cout<<"NO"<<endl;
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