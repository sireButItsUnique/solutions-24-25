#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

class Segtree {
public:
    vector<ll> tree;
    Segtree(ll n) {
        ll s = 1;
        while (s < n) {
            s *= 2;
        }
        // cout << "tree is of size " << 2 * s << endl;
        this->tree = vector<ll>(2 * s, 0);
    }    
    
    void print() {
        cout << "tree is [";
        for (ll i = 1; i < this->tree.size() - 1; i++) {
            cout << this->tree[i] << ", ";
        }
        cout << this->tree[this->tree.size() - 1] << "]\n";
        return;
    }
    
    void update(ll pos, ll val) {
        // Update leaf node
        ll at = pos + (this->tree.size() / 2);
        this->tree[at] = val;

        // Work up from leaf node
        pos = at / 2;
        while (pos) {
            this->tree[pos] = min(this->tree[pos * 2], this->tree[pos * 2 + 1]); // REPLACE WITH WHATEVER TYPE OF UPDATE TREE NEEDS
            pos /= 2;
        }
        return;
    }
    
    ll getTop() {
        return this->tree[1];
    }

    ll getRange(int start, int end) {

        // Move to leaf nodes & work up
        start += tree.size() / 2;
        end += tree.size() / 2;

        /**
        REPLACE WITH WHATEVER INITIAL VAL TREE NEEDS
        **/
        ll res = LLONG_MAX;

        while (start <= end) {
            // Only include the value at start & move to the next position if right child
            // Cannot use its parent anymore since it will be out bounds -> start++
            if (start % 2 == 1) {
                res = min(res, tree[start]); // REPLACE WITH QUERY
                start++;
            }

            // Only include the value at end & move to the next position if left child
            // Cannot use its parent anymore since it will be out bounds -> end--
            if (end % 2 == 0) {
                res = min(res, tree[end]); // REPLACE WITH QUERY
                end--;
            }

            // Move up the tree
            start /= 2;
            end /= 2;
        }
        return res;
    }
};

ll n, m;
Segtree* tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    tree = new Segtree(n);
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        tree->update(i, x);
    }
    char q;
    int idx, x, start, end;
    for (int i = 0; i < m; i++) {
        cin >> q;
        if (q == 'M') {
            cin >> idx >> x;
            tree->update(idx, x);
        } else {
            cin >> start >> end;
            cout << tree->getRange(start, end) << '\n';
        }
    }
    return 0;
}