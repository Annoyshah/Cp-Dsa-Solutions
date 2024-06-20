
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
int tt=1;
//  vector<set<int>> stu;
bool check(int mid , int n , int k , map<int,int> mp){
    map<int,int> mp2;
    // stu.clear();
    for(int i=0 ; i<k ; i++){
        set<int> st;
        for(auto &it : mp){
            if(sz(st)==mid) break;
            if(st.find(it.ff)==st.end() && it.ss>0){
                st.insert(it.ff);
                it.ss-=1;
                // if(it.ss==0) mp.erase(it.ff);
            }
        }
        mp2[sz(st)]++;
        // stu.pb(st);
        // for(auto &it : st) deb(it);
    }
    // for(auto &it : mp2) deb(it.ff);
    if(sz(mp2)==1) return true;
    return false;
}

void comderoP0612() {
int n ; int k;
cin>>n>>k;
vi v(n);
cin>>v;
vi ok(n,0);
	for (int i = 0; i < n - 1; i++) {
		ok[i] = (v[i] < 2 * v[i + 1]);
	}
 int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += ok[i];
	}
	int res = 0;
	if (cnt == k) {res++;}
	for (int i = k; i < n - 1; i++) {
		cnt += ok[i];
		cnt -= ok[i - k];
		if (cnt == k) {res++;}
	}
	cout << res << '\n';
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