#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()

using JsonMap = map<string, any>;

any getValue(JsonMap& data, const string& path) {
    if (path.empty()) return nullptr;

    vector<string> keys;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '.')) keys.pb(token);

    JsonMap* current = &data;
    for (int i = 0; i < sz(keys); i++) {
        auto it = current->find(keys[i]);
        if (it == current->end()) return nullptr; // missing key

        if (i == sz(keys) - 1) return it->second; // last key, return value

        try {
            current = &any_cast<JsonMap&>(it->second);
        } catch (...) {
            return nullptr; // not a nested map
        }
    }
    return nullptr;
}

void printValue(const any& val) {
    if (!val.has_value()) { cout << "null"; return; }
    try { cout << "\"" << any_cast<string>(val) << "\""; return; } catch (...) {}
    try { cout << any_cast<int>(val);                    return; } catch (...) {}
    try { cout << boolalpha << any_cast<bool>(val);      return; } catch (...) {}
    cout << "[nested map]";
}

void solveQ12() {
    // Build map from problem example
    JsonMap user;
    user["name"] = string("John");

    JsonMap address;
    address["city"] = string("NYC");
    address["zip"]  = string("10001");
    user["address"] = address;

    int n;
    cout << "Enter number of path queries: ";
    cin >> n;
    cout << "Enter path (e.g. name / address.city):\n";
    while (n--) {
        string path;
        cin >> path;
        cout << "getValue(user, \"" << path << "\") -> ";
        printValue(getValue(user, path));
        cout << "\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solveQ12();
    return 0;
}

//Key found, not last Dive into nested map
// Key found, lastReturn value ✅
// Key not foundreturn nullptr ✅
// Not a nested mapcatch → return nullptr ✅
// Input:
// 1
// 5
// name
// address.city
// address.zip
// address.country
// job.title