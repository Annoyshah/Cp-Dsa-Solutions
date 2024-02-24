/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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


class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    // Constructor to initialize DSU with n elements
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initially, size of each set is 1

        // Initialize each element's parent to itself
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation: Find the parent/root of a set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merge operation: Merge two sets containing elements x and y
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // Union by size: Merge smaller set into larger set
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
int power(int base, int exponent, int modulus) {
    if (modulus == 1) return 0; // Modulus 1, return 0 for any value of base

    int result = 1;
    base %= modulus; // Reduce base modulo modulus

    while (exponent > 0) {
        // If exponent is odd, multiply result with base
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        // exponent is even, square base
        base = (base * base) % modulus;
        exponent >>= 1; // Divide exponent by 2
    }

    return result;
}

void comderoP0612(){
int n;
cin>>n;
vi a(n+1) , b(n+1) , c(n+1);
for(int  i=1 ; i<=n ; i++) cin>>a[i];
for(int  i=1 ; i<=n ; i++) cin>>b[i];
for(int  i=1 ; i<=n ; i++) cin>>c[i];
DSU dsu(n);
for(int i=1 ; i<=n ; i++){
    if(a[i]==b[i])c[i]=b[i];
    dsu.merge(a[i],b[i]);
}
set<int> st;
for(int i=1 ; i<=n ; i++){
 st.insert(dsu.find(a[i]));
}
for(int i=1 ; i<=n ; i++){
    if(c[i]!=0){
        st.erase(dsu.find(c[i]));
    }
}
cout<<power(2,sz(st),mod)<<endl;
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