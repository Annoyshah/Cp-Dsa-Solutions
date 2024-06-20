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



void comderoP0612() {
string s1;
string s2;
cin>>s1;
cin>>s2;
map<char , int> mp;
map<char , int> mp2;
map<char , int> mp3;
for(auto &it : s1){
    mp[it]++;
}
for(int i=0 ; i<sz(s1) ; i++){
    mp2[s1[i]] = i;
}
for(int i=sz(s1)-1 ; i>=0 ; i--){
    mp3[s1[i]] = i;
}
if(s2[sz(s2)-1]=='X'){
    int idx = -1;
   for(int i=0 ;i<sz(s2)-1 ; i++){
           char a = tolower(s2[i]);
        
        if(mp[a]>0 && ((mp2[a]>idx) || (mp3[a]>idx) || (((mp2[a]>idx)) && ((mp3[a]>idx))))){
            mp[a]-=1;
           if(mp3[a]!=-1){
             idx = mp3[a];
            mp3[a] = -1;
           }
           else{
            for(int i=idx ; i<sz(s1) ; i++){
                if(s1[i]==a){
                    idx = i;
                    break;
                }
            }
            if(idx==mp2[i]){
                mp2[i] = -1;
            }
           }
            continue;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
}
}
else{
    int idx = -1;
    for(int i=0 ;i<sz(s2) ; i++){
        char a = tolower(s2[i]);
        
        if(mp[a]>0 && ((mp2[a]>idx) || (mp3[a]>idx) || (((mp2[a]>idx)) && ((mp3[a]>idx))))){
            mp[a]-=1;
           if(mp3[a]!=-1){
             idx = mp3[a];
            mp3[a] = -1;
           }
           else{
            for(int i=idx ; i<sz(s1) ; i++){
                if(s1[i]==a){
                    idx = i;
                    break;
                }
            }
            if(idx==mp2[i]){
                mp2[i] = -1;
            }
           }
            continue;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
}
cout<<"Yes"<<endl;
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    comderoP0612();
    return 0;
}