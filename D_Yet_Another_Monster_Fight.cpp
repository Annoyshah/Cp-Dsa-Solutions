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

template <typename T> istream& operator >> (istream& in, vector<T>& v) { for (auto &it : v) in >> it; return in; }
template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (auto &it : v) os << it << " "; return os; }
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template <typename T1, typename T2> void maxn(T1& a, T2 b) { a = max(a, b); }
template <typename T1, typename T2> void maxx(T1& a, T2 b) { a = max(a, b); }

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
#define repL(i, a, b) for(int i = (a); i < (b); i++)

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

int f(int mid, vi& vec, int maxidx) {
   
    int cnt = 0;
    int n = sz(vec);
    pii options = {0, 0};
 
    if (mid > vec[maxidx]) {
        cnt++;
        options.ff = (maxidx - 1 >= 0) ? maxidx - 1 : -1;
        options.ss = (maxidx + 1 < n) ? maxidx + 1 : n + 1;
    }
    mid--;
    while (options.ff != -1 || options.ss != n + 1) {
        if (options.ff != -1 && options.ss == n + 1){
            if (mid >= vec[options.ff]){ 
            cnt++;
            options.ff = (options.ff-1 >=0) ? options.ff-1: -1 ;
            }
            else{
                break;
            }
        } else if (options.ff == -1 && options.ss != n + 1){
            if (mid >= vec[options.ss]){ 
             cnt++;
             options.ss = ((options.ss+1)<n) ? options.ss+1 : n+1;
             }
             else{
                break;
             }
        } else {
            if (vec[options.ss] < vec[options.ff]) {
                if (mid >= vec[options.ss]){
                cnt++;
                options.ss = ((options.ss+1)<n) ? options.ss+1 : n+1;
                }
                else{
                    break;
                }
            } else if(vec[options.ss]> vec[options.ff]){
                if (mid > vec[options.ff]){
                cnt++;
                options.ff = (options.ff-1 >=0) ? options.ff-1: -1 ;
                }
                else{
                    break;
                } 
            }
            else{
                int i = options.ff;
                int j = options.ss;
                while(vec[j]==vec[i]){
                    j++;
                    i--;
                }
                if(j<n and i>=0 and vec[j]>vec[i]){
                    if(mid >= vec[options.ff]){
                    cnt++;
                     options.ff = (options.ff-1 >=0) ? options.ff-1: -1 ;
                    }
                    else{
                        break;
                    }
                }
                else if(j<n and i>=0 and vec[j]<vec[i]){
                    if(mid >= vec[options.ss]){
                         cnt++;
                         options.ss = ((options.ss+1)<n) ? options.ss+1 : n+1;
                    }
                    else{
                        break;
                    }
                }
                else if(j>n and i>=0){
                    if(mid >= vec[options.ss]){
                    cnt++;
                     options.ss = ((options.ss+1)<n) ? options.ss+1 : n+1;
                    }
                    else{
                        break;
                    }
                }
                else{
                     if(mid >= vec[options.ff]){
                    cnt++;
                     options.ff = (options.ff-1 >=0) ? options.ff-1: -1 ;
                     }
                     else{
                        break;
                     }
                }

            }
        }
        // deb(cnt);
        mid--;
    }
    // deb(cnt);
    return cnt == n;
   
}

void comderoP0612() {
    int n;
    cin >> n;
    vi vec(n, 0);
    cin >> vec;
    // deb(vec);
    int maxidx = 0;
    int max_ele = *max_element(vec.begin(), vec.end());
    int min_ele = *min_element(vec.begin(), vec.end());
  
    for (int i = 0; i < n; i++) {
        if (vec[i] == max_ele){
            maxidx = i;
            break;
        }
    }
    if(sz(vec)==1){
        cout<<max_ele<<endl;
        return;
    }
    if(sz(vec)==2){
        cout<<max_ele<<endl;
        return;
    }

    int l = max_ele;
    int r = 1e9;
    int ans = LLONG_MAX;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        //  deb(mid);
        if (f(mid, vec, maxidx)) {
            r = mid;
           ans = min(ans , mid);
        } else {
            l = mid;
        }
    }
    if(f(l , vec , maxidx)){
        cout<<l<<endl;
        return;
    }
    cout<<ans<<endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    comderoP0612();
    return 0;
}