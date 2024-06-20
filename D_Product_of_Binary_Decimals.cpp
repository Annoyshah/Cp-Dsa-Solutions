
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
int f(int st , int mid , int en , vi& price , vi& profit , int n ){
  
   if(mid == st || mid == en) return -1;
    int sum = profit[st] + profit[mid] + profit[en];
return sum; 
}
int binarySearch(vi& arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
  std::vector<int> sieve(int n) {
        std::vector<bool> isPrime(n + 1, true);
        std::vector<int> primes;
        
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        
        for (int p = 2; p <= n; ++p) {
            if (isPrime[p]) {
                primes.push_back(p);
            }
        }
        
        return primes;
    }


bool isBinaryDecimal(int num) {
   while (num > 0) {
            int d = num % 10;
            if (d != 0 && d != 1) {
                return false;
            }
            num /= 10;
        }
        return true;
}
vi pFac(int n) {
   vector<int> vec;
   vector<int> v2 = {1,10,11,100,101,110,111,121,1000,1001,1010,1011,1100,1101,1110,1111,1210,1221,1331,10000,10001,10010,10011,10100,10101,10110,10111,10201,11000,11001,11010,11011,11100,11101,11110,11111,11121,11211,12100,12111,12210,12221,12321,13310,13431,14641,100000};
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            vec.pb(i);
            n /= i;
        }
    }
    if (n > 1) {
        vec.pb(n);
    }
    return v2;
}
void comderoP0612(){
int n;
cin>>n;
if(isBinaryDecimal(n)){
    cout<<"YES"<<endl;
    return;
}
vi pf = pFac(1000000);
// deb(pf);
int tmp = n;
for(auto& it : pf){
if(it==n){
    cout<<"YES"<<endl;
    return;
}
else{
    continue;
}
}
cout<<"NO"<<endl;
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