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
int n;
cin>>n;
vector<vector<int>> matrix(n,vector<int>(n,0));
int p1 = n-1;
int p2 = n-1;
bool flag = true;
int sum = 0;
for(int i=0 ; i<n ; i++){
    int s=1;
   for(int j=0 ;j<n ; j++){
    matrix[j][p1] = s;
    s++;
   }
   s = 1;
   for(int j=0 ;j<n ; j++){
    matrix[p1][j] = s;
    s++;
   }
    p1--;
}
// for(int i=0 ;i<n ; i++){
//     deb(matrix[i]);
// }
for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
        sum+= matrix[i][j];
    }
}
 cout<<sum<<" "<<2*n<<endl;

int p=n-1;
for(int i=0 ; i<n ; i++){
    
        cout<<2<<" "<<p+1<<" ";
        for(int i=0 ; i<n ; i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
         cout<<1<<" "<<p+1<<" ";
        for(int i=0 ; i<n ; i++){
            cout<<i+1<<" ";
        } 
        cout<<endl;
        p--;
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