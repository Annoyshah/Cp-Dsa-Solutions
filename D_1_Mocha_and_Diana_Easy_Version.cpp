/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bitset>
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
#define fmp(it,mp) for(auto &it : mp)

int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int MODI(int A){
    return (A%mod2);

}
int MUL_MOD(int a , int b){
    return (a%mod2 * b%mod2)%mod2;
}
int binaryExponentiation(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = MUL_MOD(result , base);
        }
        base = MUL_MOD(base , base);
       power = power/2;
    }
    return result % mod2;
}


int di_MOD(int a , int b){
    return (MODI(a) * MODI(binaryExponentiation(b,mod2-2)))%mod2;
}
int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = MUL_MOD(result , i);
    }
    return result % mod2;
}
void dfs(int node  , vi adj[] , vi& vis , vi& ans){
    vis[node] = 1;
    ans.pb(node);
  
    for(auto &it : adj[node] ){
       if(!vis[it]){
        // deb(it);
        dfs(it , adj , vis , ans);
    }
}
}
void comderoP0612(){
      int n,m,k;
      cin>>n>>m>>k;
      vi adj1[n+1];
      vi adj2[n+1];
      set<pii> st1;
       set<pii> st2;
      for(int i=0 ; i<m ; i++){
        int x , y;
        cin>>x>>y;
        adj1[x].pb(y);
        adj1[y].pb(x);
        st1.insert({x , y});
      }
      for(int i=0 ; i<k ; i++){
        int x , y;
        cin>>x>>y;
        adj2[x].pb(y);
        adj2[y].pb(x);
            st2.insert({x , y});
      }
      cout<<min(n-1-m , n-1-k)<<endl;
      if(max(m , k)==n-1){
        return;
      }
      if(m>k && m!=n-1){
        vi vec1(n+1,0);
        vector<pii> ans;
        for(int i=1 ; i<=n ; i++){
         vec1[i] = adj1[i].size();        
         }
         int edges1 = 0;
         vi v;
         for(int i=1 ; i<=n ; i++) if(vec1[i]==0) v.pb(i);
         for(int i=0 ; i<sz(v) ; i++){
            if(edges1 >= n-1-m) break;
            ans.pb({v[i],v[i+1]});
           edges1++;
         }
         vector<pii> tmp = ans;
         for(auto &it :tmp){
            for(auto &it2 : st1){
                if(st1.find({it.ss , it2.ss})==st1.end() && st1.find({it.ss , it2.ss})==st1.end() && st2.find({it.ss ,  it2.ss})==st2.end() && st2.find({it.ss , it2.ss})==st2.end()){
                    if(sz(ans)>= n-1-m){
                        for(auto &it : ans){
                          cout<<it.ff<<" "<<it.ss<<endl;
                        }
                        return;
                    }
                    ans.pb({it.ss , it2.ss});
                    break;
                } 

            }
         }
         deb(ans);
         
      }
      if(k>m && k!=n-1){
       vi vec1(n+1,0);
        vector<pii> ans;
        for(int i=1 ; i<=n ; i++){
         vec1[i] = adj1[i].size();        
         }
         int edges1 = 0;
         vi v;
         for(int i=1 ; i<=n ; i++) if(vec1[i]==0) v.pb(i);
         for(int i=0 ; i<sz(v) ; i++){
            if(edges1 >= n-1-m) break;
            ans.pb({v[i],v[i+1]});
           edges1++;
         }
         vector<pii> tmp = ans;
         for(auto &it :tmp){
            for(auto &it2 : st2){
                if(st1.find({it.ss , it2.ss})==st1.end() && st1.find({it.ss , it2.ss})==st1.end() && st2.find({it.ss , it2.ss})==st2.end() && st2.find({it.ss , it2.ss})==st2.end()){
                    if(sz(ans)>= n-1-k){
                        for(auto &it : ans){
                          cout<<it.ff<<" "<<it.ss<<endl;
                        }
                        return;
                    }
                    ans.pb({it.ss , it2.ss});
                    break;
                } 

            }
         }
         
      }
 }
    //  cout<<n+1<<endl;

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