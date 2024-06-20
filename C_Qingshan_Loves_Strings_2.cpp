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
#define fmp(it,mp) for(auto &it : mp)

int cur=1;
const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int MODI(int A){
    return (A%mod2);

}
int MUL_MOD(int a , int b){
    return (a%mod2 * b%mod2)%mod2;
}
int binaryExponentiation(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = MUL_MOD(result , base);
        }
        base = MUL_MOD(base , base);
       power = power/2;
    }
    return result % mod2;
}


int di_MOD(int a , int b){
    return (MODI(a) * MODI(binaryExponentiation(b,mod2-2)))%mod2;
}
int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = MUL_MOD(result , i);
    }
    return result % mod2;
}


// #include <bits/stdc++.h>

bool ok(std::string s) {
  for (size_t i = 1; i < s.length(); ++i)
    if (s[i] == s[i - 1])
      return false;
  return true;
}


std::string s;
void solve() {
  int n; std::cin >> n;
  std::cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < s.length(); ++i) {
    cnt0 += s[i] == '0';
    cnt1 += s[i] == '1';
  }
  if (cnt0 != cnt1) {
    std::cout << -1 << std::endl;
    return;
  }
  std::vector<int> z;
  std::deque<char> q;
  for (int i = 0; i < s.length(); ++i)
    q.push_back(s[i]);
  
  int d = 0;
  while (!q.empty()) {
    if (q.front() == q.back()) {
      if (q.front() == '0') {
        q.push_back('0');
        q.push_back('1');
        z.push_back(n - d);
      } else {
        q.push_front('1');
        q.push_front('0');
        z.push_back(0 + d);
      }
      n += 2;
    }
    while (!q.empty() && q.front() != q.back()) {
      q.pop_back();
      q.pop_front();
      ++d;
    }
  }

  std::cout << z.size() << std::endl;
  for (int i = 0; i < z.size(); ++i) {
    std::cout << z[i];
    if (i + 1 == z.size()) std::cout << std::endl;
    else std::cout << " ";
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
    while(t--) solve();
    return 0;
}