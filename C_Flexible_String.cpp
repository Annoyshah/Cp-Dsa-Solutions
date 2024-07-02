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

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &it : v)
        in >> it;
    return in;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &it : v)
        os << it << " ";
    return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    cin >> p.first >> p.second;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    cout << p.first << " " << p.second;
    return os;
}
template <typename T1, typename T2>
void maxn(T1 &a, T2 b) { a = max(a, b); }
template <typename T1, typename T2>
void maxx(T1 &a, T2 b) { a = max(a, b); }

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
#define repL(i, a, b) for (int i = (a); i < (b); i++)
#define INF LLONG_MAX
#define NINF LLONG_MIN

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;
int tc = 1;
int countMatchingSubstrings(const string &a, const string &b) {
    int n = a.size();
    int totalSubstrings = 0;
    int consecutiveMatches = 0;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            consecutiveMatches++;
        } else {
            // Calculate the number of substrings for the current segment of matches
            totalSubstrings += (consecutiveMatches * (consecutiveMatches + 1)) / 2;
            consecutiveMatches = 0;
        }
    }
    // Add the last segment if it ended at the end of the string
    totalSubstrings += (consecutiveMatches * (consecutiveMatches + 1)) / 2;
    
    return totalSubstrings;
}
void compderoP0612()
{
   int n , k;
   cin>>n;
   cin>>k;
   string a;
   string b;
   cin>>a;
   cin>>b;
   map<char,int> mp;
   for(auto &it : a) mp[it]++;
//    tc++;
//    find the longest substring having atmost k distict charcters a[i] == b[i] nt included in distinct caharcters 
   if(k>0){
     set<char> st;
    unordered_map<char, int> freq; 
    int max_len = 0;
    int l = 0, r = 0;
    int max_l = 0, max_r = 0; 

    while (r < n) {
        if (a[r] != b[r]) {
            st.insert(a[r]);
            freq[a[r]]++;
        }
        
        while (sz(st) > k) {
            if (a[l] != b[l]) {
                if (--freq[a[l]] == 0) {
                    st.erase(a[l]);
                }
            }
            l++;
        }
        
        if ((r - l + 1) > max_len) {
            max_len = r - l + 1;
            max_l = l;
            max_r = r;
        }
        else if((r - l + 1) == max_len){
            int ans = 0;
            int ans2 = 0;
            for(int i=l ; i<=r ; i++){
                ans+=mp[a[i]];
            }
            for(int i=max_l ; i<=max_r ; i++){
                ans2+=mp[a[i]];
            }
            if(ans>ans2){
                max_l = l;
                max_r = r;
            }
        }
        
        r++;
    }
    // deb(max_len);
    // deb(max_l);
    // deb(max_r);
 
 set<char> q;

  for(int idx=max_l ; idx<=max_r ; idx++){
    if(a[idx]!=b[idx]) q.insert(a[idx]);
    a[idx] = b[idx];
  }
//    deb(sz(q));
//    for(auto &it : q) deb(it);
   for(int idx=0  ; idx<max_l ; idx++){
    if(q.find(a[idx])!=q.end()){
        a[idx] = b[idx];
    }
   } 
   for(int idx=max_r ; idx<=n-1 ; idx++){
    if(q.find(a[idx])!=q.end()){
        a[idx] = b[idx];
    }
   }
   cout<<countMatchingSubstrings(a,b)<<endl;
   }
   else{
    cout<<countMatchingSubstrings(a,b)<<endl;
   }

}
// 3 1
// abc    // a b d
// abd    // a b 

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        compderoP0612();
    }
    return 0;
}