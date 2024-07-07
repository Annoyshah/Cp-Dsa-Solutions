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


int query(int l  , int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();

    int cnt=0;
    for(int i=l , x ; i<=r ; i++){
        cin>>x;
        if(x<=r and x>=l){
            cnt++;
        }
    }
    return cnt;
}
// see there are two types of segment S1 and S2 
// s1 contains pairs that are swappd in same segment and S2 contains pairs that are swapped in different segment 
// for pairs swapped in same segemnt l to r we can count the numbers that we recieve when we query from interactor we get the number in sorte order from l to r
// the numbers swapped in same segemnt will, be even thre will be 2x such numbers and one fixed number that didn't change its position so the total numbers will be 2x + 1
// 2x+1 is odd so when we get the number in segemnt is odd we can move the l and r to foucs from whole array to that particular segment only
// another segemnt where pairs swapped are in diff segemnts they will be 2y , even 
// so we can discard elemnts of even number segment and focus binary search in odd number segemnts

void comderoP0612(){
    int n;
    cin>>n;

    int l = 1;
    int r = n;
    while(l<r){
        int mid = (l+r)/2;
        int pairsInSameSegmentPlusFixedNum = query(l , mid);
        if(pairsInSameSegmentPlusFixedNum&1){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<"! "<<l<<endl;
    cout.flush();
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