
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
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;

    set<int> st;
    map<int,int> mp;
    for(int i=0 ; i<sz(vec) ; i++) mp[vec[i]] = i;
    for(int i=1 ; i<sz(vec) ; i+=2){
        st.insert(vec[i]);
    }
  set<int> st2;
    for(int i=n ; i>=1 ; i--){
        st2.insert(i);
    }
    auto itr = st2.end();
    --itr;
    vi ans(n,0);
    // map<int,int> mp2;
    for(auto &it : st){
        ans[mp[it]] = *itr;
        auto prev = std::prev(itr);
        st2.erase(*itr);
        itr = prev;
       
    }
    // deb(ans);
    auto itr2 = st2.begin();
    set<int> st3;
    for(int i=0 ; i<sz(vec) ; i+=2){
        st3.insert(vec[i]);
    }
    for(auto it = st3.rbegin() ; it!=st3.rend() ; ++it){
        ans[mp[*it]] = *itr2;
        ++itr2;
    }

  if(check_if_peak_max(vec , ans , 1)){
    for(auto &it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return;
  }
  else{
    st.clear();
    st2.clear();
    st3.clear();
    ans.clear();
        for(int i=2 ; i<sz(vec) ; i+=2){
        st.insert(vec[i]);
    }
     set<int> st2;
    for(int i=n ; i>=1 ; i--){
        st2.insert(i);
    }
     auto itr = st2.end();
    --itr;
     ans.resize(n, 0);
    // map<int,int> mp2;
    for(auto &it : st){
        ans[mp[it]] = *itr;
        auto prev = std::prev(itr);
        st2.erase(*itr);
        itr = prev;
       
    }
    // deb(ans);
    auto itr2 = st2.begin();
    // set<int> st3;
    for(int i=1 ; i<sz(vec) ; i+=2){
        st3.insert(vec[i]);
    }
    st3.insert(vec[0]);
    for(auto it = st3.rbegin() ; it!=st3.rend() ; ++it){
        ans[mp[*it]] = *itr2;
        ++itr2;
    }
    for(auto &it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return;
  }

}


int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}