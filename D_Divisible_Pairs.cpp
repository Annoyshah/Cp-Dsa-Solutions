
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

int n , x ,y ;
cin>>n>>x>>y;
vi v(n);
cin>>v;
vector<pii> vec(n);
vector<pii> vec1(n);
map<int,int> mp;
map<int,int> mp1;
map<int , vi> mp2;
map<int , vi> mp3;
for(int i=0 ; i<n ; i++){
    vec[i] = {v[i]%x , v[i]};
}
for(int i=0 ; i<n ; i++){
    vec1[i] = {v[i]%y , v[i]};
}
for(int i=0 ; i<n ; i++){
    mp[v[i]%x]++;
}
for(int i=0 ; i<n ; i++){
   mp1[v[i]] = v[i]%y;
}
sort(all(vec));
sort(all(vec1));
// int cnt=0;
// deb(vec);
// int j=0;
// int i=vec.size()-1;
// while(j<=i){
//     if(vec[j].ff == x - vec[i].ff){

//     }
// }
for(int i=0 ; i<vec.size() ; i++){
    mp2[vec[i].ff].pb(vec[i].ss);
}
for(int i=0 ; i<vec1.size() ; i++){
    mp3[vec1[i].ff].pb(vec1[i].ss);
}
int cnt=0;
for(auto &it : mp2){
    int i = it.first; // Current key
    vector<int>& vec1 = it.second; // Vector corresponding to current key
    vector<int>& vec2 = mp2[x - i]; // Vector corresponding to x - current key
    
    // Iterate over vec1
    for(int j = 0; j < vec1.size(); j++) {
        // Iterate over vec2
        for(int k = 0; k < vec2.size(); k++) {
            if((vec1[j] - vec2[k]) % y ==0) {
                cnt++;
                // Erase the element from vec2 to ensure uniqueness
                vec2.erase(vec2.begin() + k);
                // Break from the inner loop to avoid counting the same pair multiple times
                break;
            }
        }
    }
 
}

cout<<cnt<<endl;
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