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
vector<string> results;

void digit_dp(int idx, const string &l, const string &r, string &current) {
    if (idx == l.size()) {
        results.push_back(current);
        return;
    }

    char low = l[idx];
    char high =  r[idx];

    for (char c = low; c <= high; ++c) {
        current.push_back(c);
        digit_dp(idx + 1, l, r, current);
        current.pop_back();
    }
}

vector<string> generate_strings(const string &l, const string &r) {
    results.clear();
    string current = "";
    digit_dp(0, l, r, current);
    return results;
}
bool isSubsequence(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();
    if (n > m) return false; // If b is longer than a, b cannot be a subsequence of a

    int j = 0; // Pointer for b

    // Traverse a
    for (int i = 0; i < m && j < n; ++i) {
        if (a[i] == b[j]) {
            j++;
        }
    }

    // If we have traversed all characters of b, then b is a subsequence of a
    return (j == n);
}
void comderoP0612(){
string s;
cin>>s;
int m;
cin>>m;
string l , r;
cin>>l>>r;
vector<int> v[10];
// storing indices of elements
int n = sz(s);
for(int i=0 ; i<sz(s) ; i++){
    v[s[i]-'0'].pb(i);
}
for(int i=0 ; i<10 ; i++){
    v[i].pb(n);
}
int idx=-1;
 bool flag = false;
for(int i=0 ; i<m ; i++){
    int low = l[i]-'0';
    int high = r[i] - '0';
    if(flag) break;
    int nxtidx=0;
    for(int digit = low ; digit<=high ; digit++){
        int it = upper_bound(v[digit].begin() ,v[digit].end() , idx) - v[digit].begin();
        if(v[digit][it]==n){
            flag = true;
        }
        else{
            nxtidx = max(nxtidx , v[digit][it]);
        }
    }
    idx = nxtidx;
}
if(flag){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
// store the indices of all the digits 
// now we will try to keep all numbers between range l[i] to r[i] and keep that number at the ith inex in the password that has the highest index as whn w move towards end the chances of matching of subsequnce becomes lss as string comes to an end 
// 2 1 1 3 0 9 = s
// l = 1 1 1
// r = 2 1 1
// at index0 in l and r if we keep 2 then the subseuqnce will (211 will match) match but if we keep 1 as a digit at 0th index in password (index of number that is farthest in database(matching chances reduces) and we are able to generate a password that has no commo subsequnce) 
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