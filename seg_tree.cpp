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
    Segtree(ll n) {
        // Reserve enough space for internal nodes + leaf
        ll s = 1;
        while (s < n) {
            s *= 2;
        }
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
        // Move to leaf nodes
        start += tree.size() / 2;
        end += tree.size() / 2;
        ll res = LLONG_MAX; // REPLACE WITH WHATEVER INITIAL VAL TREE NEEDS

        // Work up from leaf nodes
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