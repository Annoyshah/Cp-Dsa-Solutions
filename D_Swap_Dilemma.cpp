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
void comderoP0612(){
    int n;
    cin>>n;
    vi v1(n , 0);
    vi v2(n,0);
    cin>>v1;
    cin>>v2;
    if(v1==v2){
        cout<<"YES"<<endl;
        return;
    }
    multiset<int> st1;
    multiset<int> st2;
    for(auto &x : v1){
        st1.insert(x);
    }
    for(auto &val : v2){
        st2.insert(val);
    }
    if(st1 == st2){
        map<int,int> mp;
        for(int i=0 ; i<sz(v1) ; i++){
            mp[v1[i]] = v2[i];
        }
        bool stayanash = false;
        int pairs=0;
        for(auto &it : mp){
            if(mp[it.ss]==it.ff){
                if(it.ss!=it.ff) pairs++;
                continue;
            }
            else{
                stayanash = true;
                break;
            }
        }
        if(!stayanash){
            pairs/=2;
            if(pairs&1==1){
                cout<<"NO"<<endl;
                return;
            }
            else{
                cout<<"YES"<<endl;
                return;
            }
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    else{
        cout<<"NO"<<endl;
        return;
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