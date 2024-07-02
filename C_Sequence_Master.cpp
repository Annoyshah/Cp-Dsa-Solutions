
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
cin>>n;
vi vec(2*n,0);
cin>>vec;
// here we can buteforce for n=4 what all sequences could be by running four loops and getting a*b = d+c and a*c = b + d and a*d = b+c and b*d = a+c and b*c = a + d ad c*d = a+b
// we get a sequence -1 -1 -1 2 here , apaet from 0 0 0 0 sequnce and 2 , 2, 2 ,2 sequence which only works for  n=4
if(n==1){
    int ans1=0;
    ans1+= abs(vec[0] - vec[1]);
   cout<<ans1<<endl;
   return;
}
int ans=0;
sort(all(vec));
for(int i=0 ; i<sz(vec) ; i++){
    ans+= abs(vec[i]);
}
 if(n==2){
      int ans2=0;
    for(int i=0 ; i<sz(vec) ; i++){
        ans2+= abs(vec[i] - 2);
    }
   ans = min(ans , ans2);
}
if(n%2==0){
    int ansminusone = abs(vec[2*n-1] - n);
    for(int i=0 ; i<=2*n-2 ;i++){
        ansminusone+=  abs(vec[i]-(-1));
    }
    ans = min(ans ,  ansminusone);
}
cout<<ans<<endl;
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}