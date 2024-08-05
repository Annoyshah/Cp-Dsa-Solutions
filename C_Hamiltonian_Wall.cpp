/* ॐ श्री गणेशाय नमः || */
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

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> grid(2, vector<char>(n));
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<char>> grid2 = grid;
    int st = n;
    int cntB = 0;

    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 'B') {
            cntB++;
            st = min(st, i);
        }
        if (grid[1][i] == 'B') {
            cntB++;
            st = min(st, i);
        }
    }

    if (st == n) {
        cout << "YES\n";
        return;
    }

    vector<int> dx = {1, -1, 0};
    vector<int> dy = {0, 0, 1};

    function<int(vector<vector<char>>&, int, int)> dfs = [&](vector<vector<char>>& v, int r, int c) {
        v[r][c] = 'W';  
        int cnt = 1;

        for (int i = 0; i < 3; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if (x >= 0 && x < 2 && y >= 0 && y < n && v[x][y] == 'B') {
                cnt += dfs(v, x, y);
                break;
            }
        }
        return cnt;
    };

    int cnt = 0;
    if (grid[0][st] == 'B') cnt = dfs(grid, 0, st);
    if (grid2[1][st] == 'B') cnt = max(cnt, dfs(grid2, 1, st));

    if (cnt == cntB) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    // #ifndef ONLINE_JUDGE
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    // #endif
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
