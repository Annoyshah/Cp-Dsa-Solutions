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

vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool kmpSearch(const string& x, const string& y) {
    int m = x.size();
    int n = y.size();

    vector<int> lps = computeLPS(y);
    int i = 0;
    int j = 0;

    while (i < m) {
        if (y[j] == x[i]) {
            i++;
            j++;
        }
        if (j == n) {
            return true;
            j = lps[j - 1];
        } else if (i < m && y[j] != x[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}
bool get(string x , string y , vi& v , int n , int mid ){

    for (int i = 0; i<mid; i++){
            x[v[i]-1]='0';
    }
    int cur=0;
    for(int i=0 ; i<y.size() ; i++){
        while(cur<n && x[cur]!=y[i]){
            cur++;
        }
        if(cur>=n){
            return false;
        }
        cur++;
    }
    
    return true;
}
void comderoP0612(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.size();
    vi v(n);
    cin>>v;
    int l=0 ; int  r = n-y.size()+1;
   
    while(l+1<r){
        int mid = (l+r)/2;
        bool c = get(x,y,v,n,mid);
        
        if(c){
            l = mid;
        }
        else{
            r = mid;
        }
    }
  cout<<l<<endl;
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