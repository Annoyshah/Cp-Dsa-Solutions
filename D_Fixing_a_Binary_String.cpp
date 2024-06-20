
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


pii check_if_k_proper(string &s , int k){
    int idx1=-1;
    int idx2=-1;
    bool found = false;
    for(int i=0 ; i<sz(s) ; ){
        char a = s[i];
        int parts=1;
        for( ; parts<=k-1  ; ){
            if(a == s[i+parts]) parts++;
            else{
                idx1 = i;
                idx2 = parts;
                found = true;
                break;
            }
        }
        i = (i+k);
        if(found) break;
    }
    return {idx1  , idx2};
    
}
void comderoP0612(){
 int n , k;
 cin>>n>>k;
 string s;
 cin>>s;
//  deb(s);
if(k==1){
    int indu = -1;
    for(int i=0 ; i<sz(s)-1 ; i++){
        if(s[i]!=s[i+1]) continue;
        else indu = i;
    }
   if(indu != -1){
     if(s[indu]!=s[sz(s)-1]){
        cout<<indu+1<<endl;
        return;
    }
    else{
        if(indu>0){
             cout<<indu<<endl;
             return;
        }
        else{
             cout<<-1<<endl;
             return;
        }
    }
   }
   else{
    char h = s[sz(s)-1];
    int hi = -1;
    for(int i=0 ; i<sz(s) ; i++){
        if(s[i]!=h){
            hi = i;
        }
    }
    if(hi!=-1){
        cout<<hi+1<<endl;
        return;
    }
    else{
        cout<<-1<<endl;
        return;
    }
   }
}
 pii pr = check_if_k_proper(s,k);
 if(pr.ff!=-1 and pr.ss!=-1){
    // deb(pr);
  
    char c = s[sz(s)-1];
    int cnt=1;
    for(int idx = sz(s)-2 ; idx>=0 ; idx--){
        if(c==s[idx]){
            cnt++;
            continue;
        }
        else break;
    }
    char a = s[pr.ff + pr.ss -1];
    int cnt2=1;
    for(int idx = pr.ff + pr.ss -2 ; idx>=0 ; idx--){
        if(a==s[idx]){
            cnt2++;
            continue;
        }
        else break;
    }
    if(a==c and (cnt+cnt2)%k==0){
         int id = -1;
          if(s[pr.ff-1]==s[sz(s)-1]){
            for(int index = pr.ff - 1 ; index>=0 ; index--){
                if(s[index]!=s[sz(s)-1]){
                    id = index;
                    break;
                }
            }
          }
          int countu=0;
          id++;
          if(id>0 && id<pr.ff-1){
            while(cnt + countu < k){
            countu++;
            id++;
          }
          cout<<id<<endl;
          }
           else{
            cout<<pr.ff + pr.ss <<endl;
        }
       
    }
    else{
        cout<<-1<<endl;
        return;
    }
 }
 else{
    // cout<<"if k bahar"<<endl;
    cout<<k<<endl;
    return;
 }
}
int32_t main() { 
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin>>t;
     while(t--)comderoP0612();
    return 0;
}