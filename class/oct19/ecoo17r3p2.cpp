#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

class Node {
public:
    Node() {
        val = 0;
        maxChild = 0;
    }
    Node(int v) {
        val = v;
        maxChild = 0;
    }
    int val;
    int maxChild;
    map<int, Node*> children;
};

int rec(Node* cur) {
    //cout << "at " << cur->val << endl; 
    int res = cur->maxChild;
    for (auto& i: cur->children) {
        res += rec(i.second);
        res %= MOD;
    }
    return res;
}

// sum max of all siblings  
ll t = 10, n;
string s, id;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (t--) {
        cin >> n;
        Node* root = new Node(0);
        while (n--) {
            cin >> s;
            stringstream ss(s);
            Node* cur = root;
            getline(ss, id, '.');
            while (getline(ss, id, '.')) {
                int ID = stoi(id);
                //cout << "push " << ID << endl;
                if (!cur->children.count(ID)) {
                    cur->children[ID] = new Node(ID);
                }
                cur->maxChild = max(cur->maxChild, ID);
                cur = cur->children[ID];
            }
        }
        //cout << root->val << endl;
        cout << (rec(root) + 1) << endl;
    }

    return 0;
}