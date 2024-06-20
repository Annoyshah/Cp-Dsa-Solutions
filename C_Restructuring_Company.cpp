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
class DSU {
   public:
    DSU(int n)
        : parent_(n, -1) {
        std::set<int>::iterator it = unconnected_.end();
        for (int i = 0; i < n; ++i) {
            it = unconnected_.insert(it, i);
        }
    }

    int Find(int x) {
        if (parent_[x] < 0) {
            return x;
        }
        return parent_[x] = Find(parent_[x]);
    }

    int UnionTwo(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) {
            return x;
        }
        if (parent_[x] > parent_[y]) {
            std::swap(x, y);
        }
        parent_[x] += parent_[y];
        parent_[y] = x;
        return x;
    }

    void UnionRange(int x, int y) {
        int pos = x;
        while ((pos = *unconnected_.lower_bound(pos)) < y) {
            unconnected_.erase(pos);
            UnionTwo(pos, pos + 1);
        }
    }

   private:
    std::vector<int> parent_;
    std::set<int> unconnected_;
};
void comderoP0612(){
int n,q;
cin>>n>>q;
DSU dsu(n+1);
for(int i=0 ; i<q ; i++){
    int type , x, y;
    cin>>type>>x>>y;
    if(type==1){
        dsu.UnionTwo(x,y);
        continue;
    }
    else if(type==2){
      dsu.UnionRange(x,y);
    }
    else{
        if(dsu.Find(x)==dsu.Find(y)){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
            continue;
        }
    }
}


}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    
    comderoP0612();
    return 0;
}