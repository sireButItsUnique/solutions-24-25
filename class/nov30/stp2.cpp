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
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

/*** 
MIN RANGE QUERY SEGTREE, MODIFY AS NEEDED
ORIGINAL ARRAY (start, end, pos) INDEXES ARE 0 INDEXED
idx * 2     = left child
idx * 2 + 1 = right child
idx / 2     = parent
idx + s / 2 = use idx as leaf
***/
class Segtree {
public:
    vector<ll> tree;
    vi idx;
    Segtree(ll n) {
        // Reserve enough space for internal nodes + leaf
        ll s = 1;
        while (s < n) {
            s *= 2;
        }
        tree = vector<ll>(2 * s, 0);
        idx = vi(2 * s, INT_MAX);
    }    
    
    void print() {
        cout << "tree is [";
        for (ll i = 1; i < tree.size() - 1; i++) {
            cout << tree[i] << ", ";
        }
        cout << tree[tree.size() - 1] << "]\n";
        return;
    }
    
    void update(ll pos, ll val) {
        // Update leaf node
        ll at = pos + (tree.size() / 2);
        tree[at] = val;
        idx[at] = pos;

        // Work up from leaf node
        pos = at / 2;
        while (pos) {
            if (tree[pos * 2] == tree[pos * 2 + 1]) idx[pos] = min(idx[pos * 2], idx[pos * 2 + 1]);
            else if (tree[pos * 2] < tree[pos * 2 + 1]) idx[pos] = idx[pos * 2];
            else idx[pos] = idx[pos * 2 + 1];
            
            tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]); // REPLACE WITH WHATEVER TYPE OF UPDATE TREE NEEDS
            pos /= 2;
        }
        return;
    }
    
    ll getTop() {
        return tree[1];
    }

    ll getRange(int start, int end, int& i) {
        // Move to leaf nodes
        start += tree.size() / 2;
        end += tree.size() / 2;
        ll res = LLONG_MAX; // REPLACE WITH WHATEVER INITIAL VAL TREE NEEDS
        i = INT_MAX;

        // Work up from leaf nodes
        while (start <= end) {
            // Only include the value at start & move to the next position if right child
            // Cannot use its parent anymore since it will be out bounds -> start++
            if (start % 2 == 1) {
                //cout << tree[start] << ": " << idx[start] << "\n";
                if (res == tree[start]) i = min(i, idx[start]);
                if (tree[start] < res) i = idx[start];
                res = min(res, tree[start]); // REPLACE WITH QUERY
                start++;
            }

            // Only include the value at end & move to the next position if left child
            // Cannot use its parent anymore since it will be out bounds -> end--
            if (end % 2 == 0) {
                //cout << tree[end] << ": " << idx[end] << "\n";
                if (res == tree[end]) i = min(i, idx[end]);
                if (tree[end] < res) i = idx[end];
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

int n, q, l, r, i, x;
char op;
Segtree* tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    tree = new Segtree(n);
    for (int v, i = 0; i < n; i++) {
        cin >> v;
        tree->update(i, v);
    }

    while (q--) {
        cin >> op;
        if (op == 'M') {
            cin >> l >> r;
            l--; r--;
            int idx;
            cout << tree->getRange(l, r, idx) << " " << ++idx << "\n";
        } else {
            cin >> i >> x;
            i--;
            tree->update(i, x);
        }
    }
    return 0;
}