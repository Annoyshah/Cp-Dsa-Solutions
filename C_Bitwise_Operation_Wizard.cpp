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
#define deb(x) cout << #x << "=" << x << endl
#define pii pair<int, int>
#define vi vector<int>
#define repL(i, a, b) for (int i = (a); i < (b); i++)

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795;

char query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char response;
    cin >> response;
    return response;
}

vector<int> topo;
void canFinish(int V, vector<pii>& prerequisites) {
    vector<int> adj[V];
    vector<int> indegree(V, 0);
    
    for (auto& it : prerequisites) {
        adj[it.first].push_back(it.second);
        indegree[it.second]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto& it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
}

void comderoP0612() {
    int n;
    cin >> n;
    int maxindex = 0;
    if(n==2){
        cout<<"! "<<0<<" "<<1<<endl;
        return;
    }
    for(int i=0 ;i<n ; i++){
       char resp =  query(maxindex , maxindex , i , i);
       if(resp == '<'){
        maxindex = i;
       }
    }
    int another_no_idx=0;
    for(int i=0 ; i<n ; i++){
        char resp = query(another_no_idx , maxindex , maxindex , i);
        if(resp == '<'){
            another_no_idx = i;
        }
        else if(resp == '='){
            char resp2 = query(another_no_idx , another_no_idx , i , i);
            if(resp2 == '>'){
                another_no_idx = i;
            }
        }
    }
    cout<<"! "<<another_no_idx<<" "<<maxindex<<endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}
