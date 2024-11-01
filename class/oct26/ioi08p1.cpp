#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

// always must traverse entire tree -> except dont need to delete last word (optimal = longest word)
// traverse entire tree & back to root = 2 * nodes
class Node {
public:
    bool end = false;
    map<char, Node*> children;
};

ll n, res = 0;
string s, longWord = "";
Node* root = new Node();

void rec(Node* cur, int idx, bool isLong) {
    if (cur->end) cout << "P\n";
    Node* longNode = nullptr;
    for (auto& p : cur->children) {
        if (isLong && longWord[idx] == p.first) {
            longNode = p.second;
            continue;
        }
        cout << p.first << '\n';
        rec(p.second, idx + 1, false);
        cout << "-\n";
    }
    if (longNode) {
        cout << longWord[idx] << '\n';
        rec(longNode, idx + 1, true);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.size() > longWord.size()) longWord = s;
        res++; // print -> 1 op
        
        // add to tree
        Node* cur = root;
        for (int i = 0; i < s.size(); i++) {
            char& c = s[i];
            if (!cur->children.count(c)) {
                cur->children[c] = new Node();
                res += 2; // every node needs to be added & deleted -> 2 ops
            }
            cur = cur->children[c];
            if (i == s.size() - 1) cur->end = true;
        }
    }

    cout << (res - longWord.size()) << endl;

    // traverse tree, saving maxDepth for last
    rec(root, 0, true);
    return 0;
}