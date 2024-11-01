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
    }
    unordered_map<char, Node*> children;
};

ll t, n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int idx = 1; idx <= t; idx++) {
        cin >> n;
        Node* root = new Node();
        int res = 0;
        while (n--) {
            cin >> s;
            Node* cur = root;
            int tmp = 0;
            for (int i = 0; i < s.size(); i++) {
                if (!cur->children.count(s[i])) {
                    if (!tmp) tmp = i + 1;
                    cur->children[s[i]] = new Node();
                }
                cur = cur->children[s[i]];
            }
            if (!tmp) tmp = s.size();
            res += tmp;
        }
        cout << "Case #" << idx << ": " << res << endl;
    }
    return 0;
}