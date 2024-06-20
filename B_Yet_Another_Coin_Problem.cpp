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
// observation was that for a binary number n , its lowest significant bit is always its divisor so
// for examle 1110(14) an be converted to 1100(12) and ten to 1000(8)..Now as soon as we reach the neraest two's power i.e 8 in this example 
// another observation was that 2^k+1 is always divisible by 2^k an so on we will move till 2 by dividing the given number by 2 and then push_back 1 to the vec and sz(vec) will be our answer 

// Accepted Solution 
int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

int minSubsequenceLength(const vector<int>& nums, int target) {
    int max_target = target + 1; // Add 1 to handle the case where target is achieved exactly
    vector<int> dp(max_target, INT_MAX); // Initialize DP array with maximum values
    dp[0] = 0; // Base case: minimum length of subsequence to achieve 0 is 0

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = nums[i]; j < max_target; ++j) {
            if (dp[j - nums[i]] != INT_MAX) { // Check if it's possible to form j - nums[i]
                dp[j] = min(dp[j], dp[j - nums[i]] + 1); // Update dp[j] with the minimum length
            }
        }
    }

    return dp[target];
}
// int minSubsequenceLength(const vector<int>& nums, int target) {
    unordered_map<int, int> memo; // Memoization table

    function<int(int)> dp = [&](int t) -> int {
        if (t == 0) return 0; // Base case: minimum length of subsequence to achieve 0 is 0
        if (memo.count(t)) return memo[t]; // Return memoized value if available

        int min_len = INT_MAX;
        for (int num : nums) {
            if (t >= num) {
                int sub_len = dp(t - num);
                if (sub_len != INT_MAX) {
                    min_len = min(min_len, sub_len + 1);
                }
            }
        }

        return memo[t] = min_len; // Memoize the result and return
    };

    return dp(target);
}

void comderoP0612(){
    int n;
    cin >> n;
    int ans = n;


    cout << ans << endl;
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