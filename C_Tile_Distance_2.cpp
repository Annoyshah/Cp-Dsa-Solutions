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

int toggleKthBit(unsigned long long num, int k) {
    // Create a bitmask with the k-th bit set
    unsigned long long bitmask = 1ULL << k;

    // Toggle the k-th bit using XOR
    return num ^ bitmask;
}
struct CompareFirst {
    bool operator()(const pii &a, const pii &b) const {
        return a.ff < b.ff;
    }
};
int f(float sx, float sy, float tx, float ty) {
    unsigned long long cost = 0;

    // Adjust coordinates
    // sx += 0.5;
    // sy += 0.5;
    // tx += 0.5;
    // ty += 0.5;

    // Ensure sx <= tx
    if (sx > tx) swap(sx, tx);

    // Find the start and end points for even numbers
    int start = (sx);
    if (start % 2 != 0) start++;
    
    int end = (tx);
    if (end % 2 != 0) end--;

    // Count the number of even numbers in range
    if (start <= end) {
        cost = ((end - start) / 2) + 1;
    }

    // Add the vertical distance cost
    cost += abs(ty - sy);
    unsigned long long cost2 = (end-start);
    cost2+= abs(ty-sy)/2;
    
    // int mini = std::min(cost , cost2);
    return min(cost,cost2);
}

void comderoP0612() {
    float sx, sy;
    cin >> sx >> sy;
    float tx, ty;
    cin >> tx >> ty;

    int cost = f(sx, sy, tx, ty);
    cout << (cost - 1) << endl; // Subtract 1 as per the original logic
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    comderoP0612();
    return 0;
}
