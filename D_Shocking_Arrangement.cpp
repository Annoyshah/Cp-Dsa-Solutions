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
int tc=1;
int findMinimumSubarrySum(vi& nums){
  int n = nums.size();
        int curr_sum = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            mn = min(mn, curr_sum);
            if(curr_sum > 0) {
                curr_sum = 0;
            }
        }
        return mn;
    
}
int findMaximumSubaraySum(vi& nums){
        int n=nums.size();
        int curr_sum = 0;
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            curr_sum += nums[i];
            mx = max(mx,curr_sum);
            if(curr_sum < 0){
                curr_sum = 0;
            }
            
        }
        return mx;
}

void comderoP0612() {
  int n;
  cin>>n;
  vi vec(n,0);
  cin>>vec;
  int maxi = abs(findMaximumSubaraySum(vec));
  int mini = abs(findMinimumSubarrySum(vec));
  int max_ele = *max_element(vec.begin() , vec.end());
  int min_ele = *min_element(vec.begin() , vec.end());
  int diff = max_ele - min_ele;
  if(maxi < max_ele - min_ele and mini < max_ele - min_ele){
    cout<<"Yes"<<endl;
    for(auto &it : vec){
        cout<<it<<" ";
    }
    cout<<endl;
    return;
  }
  bool flag = 1;
  vi order;
     order.clear();
    int pos=0; int neg=0;
    for(int i=0 ; i<sz(vec) ; i++){
        if(vec[i]>0) pos++;
        else neg++;
    }
    sort(all(vec));
    // deb(vec);
    if(pos>neg){
        int i=0;
        int j=sz(vec)-1;
        int curr_sum=0;
        while(i<=j){
            curr_sum += vec[j];
            if(curr_sum<diff){
                order.pb(vec[j]);
                j--;
            }
            else{
                curr_sum-=vec[j];
                curr_sum+=vec[i];
                order.pb(vec[i]);
                i++;
            }
        }
    }
    else if(neg>pos){
        int i=0;
        int j=sz(vec)-1;
        int curr_sum=0;
        while(i<=j){
            curr_sum += vec[i];
            if(curr_sum > -diff){
                order.pb(vec[i]);
                i++;
            }
            else{
                curr_sum -= vec[i];
                curr_sum += vec[j];
                order.pb(vec[j]);
                j--;
            }
        }
    }
    else{
        int i=0;
        int j=sz(vec)-1;
        bool flag = true;
        while(i<=j){
            if(flag){
                order.pb(vec[j]);
                flag = !flag;
            }
            else{
                order.pb(vec[i]);
                flag = !flag;
            }
        }
    }
//    deb(order);
//    deb(findMinimumSubarrySum(order));
   if(abs(findMaximumSubaraySum(order))<diff and abs(findMinimumSubarrySum(order))<diff){
        cout<<"Yes"<<endl;
        for(auto &it : order){
            cout<<it<<" ";
        }
        cout<<endl;
   }
   else{
    // findSubarrays(vec,diff,order);
// deb(order);
        cout<<"No"<<endl;
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
