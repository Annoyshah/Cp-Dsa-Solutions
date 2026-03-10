#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()

void solveQ13() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++) {

        // remove elements out of window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // remove smaller elements
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // window formed
        if (i >= k - 1)
            ans.pb(nums[dq.front()]);
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solveQ13();

    return 0;
}