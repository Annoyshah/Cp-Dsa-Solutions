/*ॐ श्री गणेशाय नमः || */
/* ॐ नमः पार्वती पतये हर हर महादेव */
/* कर्पूरगौरं करुणावतारं संसारसारं भुजगेन्द्रहारम्। सदा बसन्तं हृदयारविन्दे भवं भवानीसहितं नमामि।। */
/* ॐ नमो भगवते वासुदेवाय */

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it : v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it : v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a, b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a, b); }

#define int long long int
#define ll int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define deb(x) cout << #x << "=" << x << endl;
#define pii pair<int, int>
#define vi vector<int>
#define repL(i, a, b) for(int i = (a); i < (b); i++)

const int mod = 1e9+7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

// Function to check if n is a power of 2
bool isPowerOfTwo(long long n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Function to determine if q can be formed by multiplying p with any power of 2
bool solve(int p, int q) {
    if (q % p != 0 && p % q != 0) {
        return false;
    }
    long long ratio = q / p;
    long long ratio2 = p / q;
    
    if (isPowerOfTwo(ratio) || isPowerOfTwo(ratio2)) {
        return true;
    } else {
        return false;
    }
}

void comderoP0612() {
int size; 
    cin >> size;
    vector<int> nums1(size), nums2(size); 
    cin >> nums1 >> nums2;

    // Simplify nums1 elements by continuously dividing by 2 if they are even
    for(int i = 0; i < size; i++) {
        while(nums1[i] % 2 == 0) 
            nums1[i] /= 2;
    }

    multiset<int> set1, set2;


    for(int i = 0; i < size; i++) {
        set1.insert(nums1[i]);
        set2.insert(nums2[i]);
    }

    while(!set2.empty()) {
        int maxElem = *set2.rbegin();
        
        if(!set1.count(maxElem)) {
            if(maxElem == 1) break;
            set2.erase(--set2.end());
            set2.insert(maxElem / 2);
        } else {
            set1.erase(set1.find(maxElem));
            set2.erase(set2.find(maxElem));
        }
    }

    if(set2.empty()) 
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int32_t main() { 
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
