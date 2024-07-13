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
template <typename T1, typename T2> istream& operator >> (istream& in, pair<T1, T2>& p) { cin >> p.first >> p.second; return in; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { cout << p.first << " " << p.second; return os; }
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
const long long INF = LLONG_MAX;

struct Edge {
    int to;
    long long weight;
};

void comderoP0612() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<long long> nodeWeights(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        cin >> nodeWeights[i];
    }

    vector<vector<Edge>> adjList(numNodes + 1);
    for (int i = 0; i < numEdges; ++i) {
        int fromNode, toNode;
        long long edgeWeight;
        cin >> fromNode >> toNode >> edgeWeight;
        adjList[fromNode].push_back({toNode, edgeWeight});
        adjList[toNode].push_back({fromNode, edgeWeight});
    }

    auto dijkstra = [&](int sourceNode) {
        vector<long long> minPathWeight(numNodes + 1, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> priorityQueue;
        
        minPathWeight[sourceNode] = nodeWeights[sourceNode - 1];
        priorityQueue.emplace(nodeWeights[sourceNode - 1], sourceNode);

        while (!priorityQueue.empty()) {
            long long currentWeight = priorityQueue.top().first;
            int currentNode = priorityQueue.top().second;
            priorityQueue.pop();
            
            if (currentWeight > minPathWeight[currentNode]) continue;

            for (const auto& edge : adjList[currentNode]) {
                int nextNode = edge.to;
                long long totalWeight = currentWeight + edge.weight + nodeWeights[nextNode - 1]; 

                if (totalWeight < minPathWeight[nextNode]) {
                    minPathWeight[nextNode] = totalWeight;
                    priorityQueue.emplace(totalWeight, nextNode);
                }
            }
        }

        for (int i = 2; i <= numNodes; ++i) {
            cout << minPathWeight[i] << " ";
        }
        cout << endl;
    };

    dijkstra(1);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    comderoP0612();
    return 0;
}
