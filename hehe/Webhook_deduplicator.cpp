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

class WebhookDeduplicator {
    map<string, int> mp;
    const int WINDOW = 900000;

    void cleanup(int now) {
        vector<string> expired;
        for (auto& it : mp) {
            if (now - it.ss >= WINDOW) {
                expired.pb(it.ff);
            }
        }
        for (int i = 0; i < sz(expired); i++) {
            mp.erase(expired[i]);
        }
    }

public:
    bool isNewEvent(string eventId, int timestampMillis) {
        if (eventId.empty() || timestampMillis < 0) return false;
        cleanup(timestampMillis);
        auto it = mp.find(eventId);
        if (it != mp.end() && timestampMillis - it->second < WINDOW) {
            return false;
        }
        mp[eventId] = timestampMillis;
        return true;
    }
};


void comderoP0612() {
    WebhookDeduplicator wd; 

    int n;
    cin >> n;
    while (n--) {
        string eventId;
        int timestamp;
        cin >> eventId >> timestamp;
        cout << "isNewEvent(\"" << eventId << "\", " << timestamp << ") -> "
             << boolalpha << wd.isNewEvent(eventId, timestamp) << "\n";
    }
    
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) comderoP0612();
    return 0;
}