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

int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;



const int N = 200000;
int n, k;
int a[N+5], h[N+5], pref[N+5], length[N+5];
int binarySearch(const std::vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == target) {
            return mid; // Element found
        } else if (vec[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int countDistinctInRange(const std::vector<int>& vec, int l, int r) {
    // Sort the vector
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    // Find the positions of l and r in the sorted vector
    int lIndex = binarySearch(sortedVec, l);
    int rIndex = binarySearch(sortedVec, r);

    // Handle the case when l or r are not present in the vector
    if (lIndex == -1) lIndex = std::upper_bound(sortedVec.begin(), sortedVec.end(), l) - sortedVec.begin();
    if (rIndex == -1) rIndex = std::upper_bound(sortedVec.begin(), sortedVec.end(), r) - sortedVec.begin();

    // Count the number of distinct elements between lIndex and rIndex
    int distinctCount = std::set<int>(sortedVec.begin() + lIndex, sortedVec.begin() + rIndex).size();

    return distinctCount;
}

void comderoP0612(){
   int n,q;
   cin>>n>>q;
   vi v(n);
   cin>>v;
   for(int i=0 ; i<q ; i++){
    int x , y;
    set<int> st;
    vi vec = v;
    sort(all(vec));
    cin>>x>>y;
    map<int,int> mp;
  if(x!=y && x<y){
    int num = y-x+1;
    int st = countDistinctInRange(vec,x-1,y-1);
    int repeated = num - st;
   if(st>=repeated){
    cout<<"YES"<<endl;
   }
   else{
    cout<<"NO"<<endl;
   }
   }
   if(x==y){
    cout<<"NO"<<endl;
    continue;
   }
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