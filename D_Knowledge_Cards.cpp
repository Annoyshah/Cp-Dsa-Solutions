
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

bool check(int mid, vector<vi>& pref, vector<int>& vec) {
    int n = sz(vec);
    if (mid > n) return false;
    
    int q = mid - 1;
    int prev_or = 0;
    for (int j = 20; j >= 0; j--) {
        if (pref[q][j] > 0) prev_or |= (1 << j);
    }

    bool found = false;
    for (int i = 1; i + mid - 1 < n; i++) {
        int cur_or = 0;
        int k = i + mid - 1;
        for (int j = 20; j >= 0; j--) {
            if ((pref[k][j] - pref[i - 1][j]) > 0) cur_or |= (1 << j);
        }
        if (prev_or != cur_or) {
            found = true;
            break;
        }
    }
    return !found;
}
bool check_if_peak_max(vector<int>& p , vector<int>& q , int r){
    vi ans(sz(p),0);
    bool found = false;
    for(int i=0 ; i<sz(p) ; i++){
       ans[i] = p[i] + q[i];
    }
    for(int i=1*r ; i<sz(p)-1 ; i+=2){
        if(ans[i] > ans[i-1] and ans[i] > ans[i+1]) continue;
        else{
            found = true;
            break;
        }
    }
    return !found;
}
void comderoP0612() {
  int n , m ,k;
  cin>>n>>m>>k;
  vi vec(k,0);
  cin>>vec;
  stack<int> st;
  for(int i=k-1 ; i>=0 ; i--){
    st.push(vec[i]);
  }
  vector<vector<int>> vis(n,vector<int>(m,0));
  sort(all(vec));
  bool nai_ho_skta = false;
  while(!st.empty()){
    int top = st.top();
    st.pop();
    if(vec.back()==top){
        vec.pop_back();
        continue;
    }
    else{
        bool placed = false;
        for(int i=0 ; i<n-1 ; i++){
            for(int j=m-1 ; j>=1 ; j--){
                if(vis[i][j]==0){
                    vis[i][j] = 1;
                    placed = true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(placed) break;
        }
        if(placed) continue;
        if(!st.empty() and !placed){
            for(int j=m-2 ; j>=0; j--){
                if(vis[n-1][j]==0) {
                vis[n-1][j] = 1;
                placed = true;
                break;
            }
            if(!placed){
                for(int i=0 ; i<n-1 ; i++){
                    if(vis[i][0]==0){
                    vis[i][0] = 1;
                    placed = true;
                    break;
                    }
                }
              }
            if(!placed){
                nai_ho_skta = true;
                break;
            }
            }
        }
        if(nai_ho_skta) break; 
    }
  }
      int cnt=0;
  if(nai_ho_skta){
    cout<<"TIDAK"<<endl;
    return;
  }
  else{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(vis[i][j]==0) cnt++;
        }
      }
    
  if(cnt-2>=2){
    cout<<"YA"<<endl;
  }
  else{
    cout<<"TIDAK"<<endl;
   }
  }
  }
int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}