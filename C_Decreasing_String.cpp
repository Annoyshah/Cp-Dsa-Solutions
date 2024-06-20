
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

bool check(int mid , int n , int k , map<int,int> mp){
    // deb(mid);
    if(n>1){
        vi tstamp(n+1,0);
    for(auto &it : mp){
        // deb(it.ss);
        if(it.ss >= mid ){
            it.ss-=mid;
            tstamp[it.ff] = (mid);
        }
        else{
            
            tstamp[it.ff] = (it.ss);
            it.ss=0;
        }
    }
    int sum=0;
    for(auto &it : mp){
       sum+= (2*it.ss);
    }
    // deb(sum);
    for(int i=1 ; i<=n ; i++){
        // deb(i);
        // deb(tstamp[i]);
        // deb(sum);
        if(tstamp[i]<mid and sum + tstamp[i] >= mid) sum-=(mid - tstamp[i]);
        else if(tstamp[i]<mid and sum + tstamp[i]<=mid) sum = 0;
    }
    if(sum == 0 && tstamp[n]<=mid) return true;
    }
    else{
        return(mid>=mp[1]);
    }
    // deb(sum);
    
    return false;
}
//jcext cext cet ce c
void find(vi& cnt , string& s ){
    // deb(s);
    int last=-1;
    for(int i=0 ; i<sz(cnt) ; i++){
        if(cnt[i]>0) last = i;
    }
    // deb(last);
    if(last!=-1 && last<=26){
    cnt[last]--;
   int idx = -1;
   for(int i=0 ; i<sz(s) ; i++){
    if(s[i]==(last + 'a')){
        idx = i;
        break;
    }
   }
//    deb(idx);
   if(idx>-1 & idx<sz(s))s.erase(s.begin() + idx);
}
}
string find2(string& s){
 if (!s.empty()) {
        s.erase(s.begin() + (sz(s)-1));
    }
    return s;
}
void comderoP0612() {


 string s;
    cin >> s;
    int id;
    cin >> id;

    vi cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }

    vector<int> order;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1]) {
            order.push_back(i);
        }
    }
    if(id<= sz(s)){
        cout<<s[id-1];
        return;
    }

    string str2 = s;
    int n = s.size();
    int size = order.size();
    int preSum = n * (n + 1) / 2 - ((n - size) * (n - size + 1)) / 2 + (n - size);

    if (size > 0) {
        for (int i = 0; i < order.size(); i++) {
            string str1 = s;
            for (int j = 0; j <= i; j++) {
                if (!str1.empty()) {
                    cnt[str1[order[j]] - 'a']--;
                    str1.erase(str1.begin() + order[j]);
                }
            }
            str2 += str1;
        }
        deb(str2);
        for (int i = 0; i < sz(order); i++) {
            if (order[i] < s.size()) {
                s.erase(s.begin() + order[i]);
            }
        }
    }
    if (id >= preSum) {
        int l = 0;
        for (int x = size; x <= s.size() - 1; x++) {
            int sum = n * (n + 1) / 2 - ((n - x) * (n - x + 1)) / 2 + (n - x);
            if (id <= sum) {
                l = x;
                break;
            }
        }
       
        for (int i = 1; i <= l + 1; i++) {
            str2 += find2(s);
        }
        if (id - 1 < str2.size()) {
            cout << str2[id - 1];
            return;
        } else {
            int k=0;
            for (int x = l; x <= s.size() - 1; x++) {
            int sum = n * (n + 1) / 2 - ((n - x) * (n - x + 1)) / 2 + (n - x);
            if (id <= sum) {
                k = x;
                break;
            }
        }
         for (int i = 1; i <= l + 1; i++) {
            str2 += find2(s);
        }
         if (id - 1 < str2.size()) {
            cout << str2[id - 1];
            return;
        }
        }
        return;
    } else {
        if (id - 1 < str2.size()) {
            cout << str2[id - 1];
            return;
        }
        
    }
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