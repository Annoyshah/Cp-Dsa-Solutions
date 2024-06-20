/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bitset>
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
bool check_forward(const vi &a, const vi &p, int &left_reach) {
    int cnt = 1;
    for (int i = 0; i < a.size(); i++) {
        if (i == a.size() - 1) {
            break;
        }
        if (a[i] + p[i] >= a[i + 1]) {
            left_reach = i + 1;
        } else {
            cnt++;
        }
    }
    return cnt <= 2;
}

bool check_backward(const vi &a, const vi &p, int &right_reach) {
    int cnt = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (i == 0) {
            break;
        }
        if (a[i] - p[i] <= a[i - 1]) {
            right_reach = i - 1;
        } else {
            cnt++;
        }
    }
    return cnt <= 2;
}

bool check_reachable_from_middle(const vi &a, const vi &p) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - p[i] <= a[i - 1]) {
            continue;
        } else {
            for (int j = i; j < a.size(); j++) {
                if (j == a.size() - 1) {
                    return true;
                }
                if (a[j] + p[j] >= a[j + 1]) {
                    continue;
                } else {
                    break;
                }
            }
            break;
        }
    }
    return false;
}

bool can_reach_end(const vi &a, const vi &p) {
    int left_reach = 0;
    int right_reach = a.size() - 1;

    if (check_forward(a, p, left_reach) || check_backward(a, p, right_reach)) {
        return true;
    }

    if (left_reach + 1 >= right_reach) {
        return true;
    }

    return check_reachable_from_middle(a, p);
}

bool canReachEnd(vector<int>& positions, vector<int>& power, int n) {
    bool result = false;
    int count = 1;

    // Check from left to right
    for (int i = 0; i < n; i++) {
        if (i == n - 1) break;
        if (positions[i] + power[i] >= positions[i + 1]) {
            // Do nothing, continue
        } else {
            count++;
        }
    }
    
    if (count <= 2) result = true;

    count = 1;

    // Check from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0) break;
        if (positions[i] - power[i] <= positions[i - 1]) {
            // Do nothing, continue
        } else {
            count++;
        }
    }

    if (count <= 2) result = true;

    int leftReach = 0;
    for (int i = 0; i < n; i++) {
        if (positions[i] + power[i] >= positions[i + 1]) {
            leftReach = i + 1;
        } else {
            break;
        }
    }

    int rightReach = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (positions[i] - power[i] <= positions[i - 1]) {
            rightReach = i - 1;
        } else {
            break;
        }
    }

    if (leftReach + 1 >= rightReach) result = true;
    if (result) {
        cout << "YES" << endl;
        return true;
    }

    // Check left-right case
    for (int i = 1; i < n; i++) {
        if (positions[i] - power[i] <= positions[i - 1]) {
            continue;
        } else {
            // Try to reach the end from here
            for (int j = i; j < n; j++) {
                if (j == n - 1) {
                    result = true;
                }
                if (positions[j] + power[j] >= positions[j + 1]) {
                    continue;
                } else {
                    break;
                }
            }
            break;
        }
    }

    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return result;
}
void comderoP0612(){
 int n;
 cin>>n;
 vi x(n,0);
 cin>>x;
 vi p(n,0);
 cin>>p;

//  vi left(n,0);
//  vi right(n,0);
//  if(p[0]>=x[1]-x[0]) right[0]=1 , left[0]=0;
//  if(p[n-1]>=x[n-1]-x[n-2]) left[n-1]=1 , right[n-1]=0;
//  for(int i=1 ; i<sz(x)-1 ; i++){
//     if(p[i]>=x[i+1]-x[i]) right[i]=1 , left[i]=0;
//     else if(p[i]>=x[i]-x[i-1]) left[i]=1 , right[i]=0;
//  }

canReachEnd(x, p, n);



 }
    //  cout<<n+1<<endl;

int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
   while(t--)comderoP0612();
    return 0;
}