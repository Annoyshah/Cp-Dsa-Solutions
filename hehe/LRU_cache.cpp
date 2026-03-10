#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
    Node* tail;

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {

        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        int value = node->val;

        deleteNode(node);
        addNode(node);

        mp[key] = node;

        return value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }

        if(sz(mp) == cap) {

            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

void solveQ13() {

    int capacity;
    cin >> capacity;

    int q;
    cin >> q;

    LRUCache cache(capacity);

    while(q--) {

        string op;
        cin >> op;

        if(op == "put") {

            int key,val;
            cin >> key >> val;

            cache.put(key,val);
        }
        else if(op == "get") {

            int key;
            cin >> key;

            cout << cache.get(key) << "\n";
        }
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while(t--)
        solveQ13();

    return 0;
}