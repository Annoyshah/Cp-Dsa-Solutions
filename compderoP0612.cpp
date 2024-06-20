
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
bool ArrayChallenge(vector<int> arr) {
    int target = *max_element(arr.begin(), arr.end());
    auto it = find(arr.begin(), arr.end(), target);
    if (it != arr.end()) arr.erase(it);

    int n = arr.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target] ? true : false;
}
bool subsetSumUtil(int ind, int target, int arr[], vector<vector<int>>& dp) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}
bool ArrayChallenge(int arr[] , int n){
    
    //  std::sort(arr , arr+n);
    int k = *max_element(arr , arr+n);
      int size = n - 1;
    int newArr[size];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] != k) {
            newArr[index++] = arr[i];
        }
    }
    vector<vector<int>> dp(size+1, vector<int>(k+1, -1));
 return subsetSumUtil(size-1 , k , newArr, dp );
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    int arr[5] = {5,7,16,1,2};
   cout<<ArrayChallenge(arr , 5);
   cout<<"Hi"<<endl;
    return 0;
}