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
bool haveSameOccurrences( std::string str1,  std::string str2) {
    // Maps to store character occurrences in both strings
    std::unordered_map<char, int> count1, count2;

    // Count occurrences of characters in str1
    for (char c : str1) {
        count1[c]++;
    }

    // Count occurrences of characters in str2
    for (char c : str2) {
        count2[c]++;
    }

    // Compare the occurrences of each character
    for (const auto& pair : count1) {
        char c = pair.first;
        if (count2[c] != count1[c]) {
            return false;
        }
    }

    // Check if str2 has any extra characters not present in str1
    for (const auto& pair : count2) {
        char c = pair.first;
        if (count1.find(c) == count1.end()) {
            return false;
        }
    }

    return true;
}
void opr1(int i , string& s1 , string& s2 ){
    int j = i+1;
    for( ; j<=sz(s1) ;j++){
        if(s1[j]=='a') continue;
        else{
            if(s1[j]=='b'){
            s1[i]='b';
            s1[j]='a';
            break;
        }
        else{
            return;
        }
        }
       
    }
}
void opr2(int i , string& s1 , string& s2 ){
    int j = i+1;
    for( ; j<=sz(s1) ;j++){
        if(s1[j]=='b') continue;
       else{
         if(s1[j]=='c'){
            s1[i]='c';
            s1[j]='b';
            break;
        }
        else{
            return;
        }
       }
    }
}
void opr3(int i , string& s1 , string& s2 ){
    if(i>0){
    int j = i-1;
    for( ; j>=0 ;j--){
        if(s1[j]=='b') continue;
       else{
         if(s1[j]=='a'){
            s1[i]='a';
            s1[j]='b';
            break;
        }
        else{
            return;
        }
       }
    }
}
}
void opr4(int i , string& s1 , string& s2 ){
    if(i>0){
    int j = i-1;
    for( ; j>=0 ;j--){
        if(s1[j]=='c') continue;
       else{
         if(s1[j]=='b'){
            s1[i]='b';
            s1[j]='c';
            break;
        }
        else{
            return;
       }
       }
    }
}
}

void comderoP0612(){
int n;
cin>>n;
string s1;
string s2;
cin>>s1;
cin>>s2;

if(haveSameOccurrences(s1,s2)){
    for(int i=0 ; i<n ; i++){
        if(s1[i]==s2[i]){
            continue;
        }
        else{
            if(s1[i]=='a' && s2[i]=='b'){
                opr1(i,s1,s2);
                if(s1[i]==s2[i]){ 
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(s1[i]=='b' && s2[i]=='c'){
                opr2(i,s1,s2);
                  if(s1[i]==s2[i]){ 
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(s1[i]=='b' && s2[i]=='a'){
                opr3(i,s1,s2);
                  if(s1[i]==s2[i]){ 
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(s1[i]=='c' && s2[i]=='b'){
                opr4(i,s1,s2);
                  if(s1[i]==s2[i]){ 
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }

            }
    }
    }
    
}
else{
    cout<<"NO"<<endl;
    return ;
}
if(s1==s2){
        cout<<"YES"<<endl;
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