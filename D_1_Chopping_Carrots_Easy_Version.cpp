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

// whole intutition:
// i have a1...ai..an
// if i want min(max_of_all(ai/pi) - min_of_all(ai/pi));
// then max_of_all(ai/pi)  must be equal to min_of_all(ai/pi)) i.e all values of ai/pi must be same
// or then values of ma_of_all(ai/pi) must be equal to min_of_all(ai/pi)
// if we cannot make all the values same we will make sure they are closer
// ai ..... an in sorted manner 
// mini = min_ele(all(ai));
// maxi = min_ele(all(ele))
// mini/1...mini/k
// we will try for all values from 1 to min_element and try t make all the other elemnts either min_elemnt by dividing with pi or will make them most closer to min-element
// why only min_element , bcoz if we take any mid element betwenn min and max of ai , then smaller values than mid cant be made equal to any mid element between mini and maxi element
// 5 8 15
// now how to find if we can make a number from ai
// let for(i=0...min_ele){
//  if(i==4) then we divide 5/4 = 1 and again divide 5/1 = 5 if a[i]/(num we want to make) = x and a[i]/x = (num_we want to make) then we can make that number but if a[i]/x != (number we want to make) then the nmber we obtained by dividing a[i]/x = p , p is the closet number we can make to number we want to make


// }
void comderoP0612() {
  int n,k; 
  cin>>n>>k;
    vi v(n); 
    cin>>v;
    int min_an=LLONG_MAX;
    for(int i=1;i<=v[0];i++){
        int maxudi=i;
        for(int j=0;j<n;j++)
        {
            int req=min(k,v[j]/i);
            maxudi=max(maxudi,v[j]/req);
        }
        min_an=min(min_an,maxudi-i);
    }
    cout<<min_an<<endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}