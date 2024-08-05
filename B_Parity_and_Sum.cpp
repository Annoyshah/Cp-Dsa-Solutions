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
void placeatIdx(int idx , vi& vec , int& largest_odd , int& largest_even , int& operations){
     repL(i,0,sz(vec)) {
        if (vec[i] % 2 == 1 && vec[i] == largest_odd) {
            idx = i;
            break;
        }
    }

    vec[idx] = largest_even + largest_odd;
    operations++;
}
void coutnoperations(int& operations , vi& vec){
    repL(i,0,sz(vec)){
        if ((vec[i]&1) == 0) {
            operations++;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vi vec(n,0);
    cin>>vec;

    int largest_odd = 0;
    int largest_even = 0;
    bool sab_same = true;
    multiset<int> odd;
    multiset<int> even;
    int operations = 0;

    
    for (auto &it : vec) {
        if (it % 2 == 0) {
            even.insert(it);
        } else {
            odd.insert(it);
        }
    }


    if (odd.empty() || even.empty()) {
        sab_same = true;
    } else {
        largest_odd = *(--odd.end());
        largest_even = *even.begin();
        sab_same = false;
    }

    if (sab_same) {
        cout << 0 << endl;
        return;
    }

    sort(all(vec));
    repL(i,0,n){
        if (((vec[i]&1)==0) && vec[i] < largest_odd) {
            vec[i] += largest_odd;
            operations++;
            largest_odd = max(largest_odd, vec[i]);
        }
    }

    sab_same = true;
    for (int i = n - 2; i >= 0; i--) {
        if (vec[i] % 2 != vec[n - 1] % 2) {
            sab_same = false;
            break;
        }
    }

    if (sab_same) {
        cout << operations << endl;
        return;
    }

    int idx = 0; 
   
    placeatIdx(idx , vec , largest_odd , largest_even , operations);

    
    coutnoperations(operations , vec);

    cout << operations << endl;
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