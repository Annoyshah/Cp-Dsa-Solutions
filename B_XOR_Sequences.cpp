
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

int slidingWindowMaximumMin(const vector<int>& arr, int k) {
    deque<int> dq;
    int min_of_maximums = INT_MAX;

    for (int i = 0; i < arr.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            int current_max = arr[dq.front()];
            if (current_max < min_of_maximums) {
                min_of_maximums = current_max;
            }
        }
    }

    return min_of_maximums;
}

int findMinimumOfMaximums(const vector<int>& arr) {
    int n = arr.size();
    int overall_min_of_maximums = INT_MAX;

    for (int k = 2; k <= n; ++k) {
        int current_min_of_maximums = slidingWindowMaximumMin(arr, k);
        if (current_min_of_maximums < overall_min_of_maximums) {
            overall_min_of_maximums = current_min_of_maximums;
        }
    }

    return overall_min_of_maximums;
}
bool isDivisionInteger(int numerator, int denominator) {
    // Ensure denominator is not zero to avoid division by zero error
    if (denominator == 0) {
        cout << "Error: Division by zero!" << endl;
        return false;
    }
    
    return (numerator % denominator == 0);
}
bool canbebroken(int mid , vi& vec){
    int sum=0;
    for(int i=0 ; i<sz(vec) ; i++){
        int ans = (mid/vec[i]);
        sum+= (ans+1);
    }
    if(sum == mid){
        return true;
    }
    return false;
}
void comderoP0612(){
 int x;
 int y;
 cin>>x;
 cin>>y;
 string str1="";
 string str2="";
 int maxbt = 0;
 for(int i=0 ; i<=32 ; i++){
    if(pow(2,i) > max(x,y)){
        maxbt = i;
        break;
    }
 }
 for(int bit=maxbt ; bit>=0 ; bit--){
    str1+= to_string((x>>bit) & 1);
    str2+= to_string((y>>bit) & 1);
 }
//  deb(str1);
//  deb(str2);
 string cstr1 = "";
 string cstr2 = "";
 for(int i=0 ; i<sz(str1) ; i++){
    cstr1+= (str1[i]=='1') ? '0' : '1';
    cstr2+= (str2[i]=='1') ?  '0' : '1';
 }
 int cnt=1;
 int idx = 0;
 for(int i=sz(cstr1)-1 ; i>=0; i--){
    if(cstr1[i]==cstr2[i]){
        idx++;
        continue;
    }
    else{
        break;
    }
 }
//  int po = cstr1.size() - idx - 1;
 double largeNuber =  pow(2,idx) ;
 std::cout << std::fixed << std::setprecision(0) << largeNuber << std::endl;
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin>>t;
     while(t--)comderoP0612();
    return 0;
}