/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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

int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find relatively prime pairs that multiply to X
vector<pair<int, int>> relativelyPrimePairs(int X) {
    vector<pair<int, int>> pairs;
    
    for (int i = 1; i <= X; ++i) {
        if (X % i == 0) {
            int divisor = i;
            int quotient = X / divisor;
            
            if (gcd(divisor, quotient) == 1) {
                pairs.push_back({divisor, quotient});
            }
        }
    }
    
   
    return pairs;
}

void comderoP0612(){
int x;
cin>>x;
vector<pii> vec;
for(int i=1 ; i<x ; i++){
    int b = x/i;
    if(i<b && gcd(i,b)==1 && i*b==x){
        vec.pb({i,b});
        continue;
    } 
    if(i>b) break;
    
}
   if(vec.empty()){
    cout<<1<<" "<<x<<endl;
    return;
   } 

   vi v;
   for(auto x : vec){
    v.pb(max(x.ff,x.ss));
   }
   
int mini = *min_element(v.begin(),v.end());
cout<<x/mini<<" "<<mini<<endl;


}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    comderoP0612();
    return 0;
}