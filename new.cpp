// #include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it:v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it:v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { cout << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a,b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a,b); }

#define int long long
#define ll long long
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


 vector<vector<int>> memo;
 int fillinDP(int n , int k){
      
     for (int idx1 = 2; idx1 <= n; idx1++) {
            for (int j = 1; j <= idx1; ++j) {
            memo[idx1][j] += (j - 1 >= 0) ? memo[idx1 - 1][j - 1] : 0;
                // memo[idx1][j] += (j <= idx1 - 1) ? memo[idx1 - 1][j] : 0;
                if(j>idx1-1){
                    memo[idx1][j] += 0;
                }
                else{
                    memo[idx1][j] += memo[idx1-1][j];
                }
            }
        }
        return memo[n][k];
 }
 int theLastChocolate(int n, int k) {
        memo = vector<vector<int>> (n + 1, vector<int>(k + 1, 0));
        memo[1][1] = 1;
        return fillinDP(n,k);
    }
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
void buildPrefixArray(vector<int>& prefixMax , int arr[] , int n){
for(int i=1 ; i<n ; i++){
    prefixMax[i] = max(prefixMax[i-1] , arr[i]);
}
}
int calculateSum(int n, int arr[]) {
    
    // int maximum_till_i = arr[0];
    vector<int> prefixMax(n,INT_MIN);
    prefixMax[0] = arr[0];
    buildPrefixArray(prefixMax , arr , n);
    vector<int> vec;
    deb(prefixMax);
    for (int i = 0; i < n; ++i) {
        // maximum_till_i = prefixMax[i];
        vec.push_back(gcd(arr[i], prefixMax[i]));
    }
   sort(vec.begin() , vec.end());
   deb(vec);
    int sumgcd = 0;
    for (int i = 0; i < n / 2; ++i) {
        sumgcd += __gcd(vec[i], vec[n - 1 - i]);
    }

    return sumgcd;
}
int32_t main() {
//     int n1;int n2;
//     cin>>n1>>n2;
//    cout<<theLastChocolate(n1,n2)<<endl;
int n;
cin>>n;
deb(n);
int arr[5];
for(int i=0 ; i<n ; i++){
    cin>>arr[i];
    deb(arr[i]);
}

cout<<calculateSum(n,arr)<<endl;
return 0;
}