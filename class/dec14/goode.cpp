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

class Segtree {
public:
    vector<ll> tree, lazy;
    ll s; // s = size of segtree arr

    // Reserves enough space for tree
    Segtree(ll size) {
        s = 1;
        while (s < size) s *= 2;
        tree.assign(2 * s, 0);
        lazy.assign(2 * s, 0);
    }

    void pushUpdate(ll idx, ll start, ll end) {
        if (lazy[idx]) {

            if (start != end) { // Propagate to children
                ll mid = (start + end) / 2;
                lazy[idx * 2] ^= 1;
                tree[idx * 2] = (mid - start + 1) - tree[idx * 2];
                lazy[idx * 2 + 1] ^= 1;
                tree[idx * 2 + 1] = (end - (mid + 1) - 1) - tree[idx * 2 + 1];
            }

            lazy[idx] = 0; // Clear the lazy value
        }
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    void rangeUpdate(ll l, ll r, ll diff, ll idx, ll start, ll end) {

        if (start > r || end < l) return; // No overlap, don't do anything

        if (start >= l && end <= r) { // Full overlap, update & stop here 
            lazy[idx] ^= 1;
            tree[idx] = (end - start + 1) - tree[idx];
            pushUpdate(idx, start, end);
            return;
        }

        // Else keep trickling down to children
        ll mid = (start + end) / 2;
        rangeUpdate(l, r, diff, idx * 2, start, mid);
        rangeUpdate(l, r, diff, idx * 2 + 1, mid + 1, end);

        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // Update current node: What happens to res when you combine both intervals
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    ll rangeQuery(ll l, ll r, ll idx, ll start, ll end) {
        pushUpdate(idx, start, end);

        if (start > r || end < l) return 0; // No overlap: Return val which won't change res

        if (start >= l && end <= r) return tree[idx]; // Full overlap, return its val

        ll mid = (start + end) / 2;
        ll leftRes = rangeQuery(l, r, idx * 2, start, mid);
        ll rightRes = rangeQuery(l, r, idx * 2 + 1, mid + 1, end);

        return leftRes + rightRes; // Combine left and right: What happens to the res if you include both?
    }

    void rangeUpdate(ll l, ll r, ll diff) {
        rangeUpdate(l, r, diff, 1, 1, s);
    }

    ll rangeQuery(ll l, ll r) {
        return rangeQuery(l, r, 1, 1, s);
    }

    void update(ll idx, ll diff) {
        rangeUpdate(idx, idx, diff);
    }

    int bin(int val, int idx, int start, int end) {
        if (start == end) return start;
        if (lazy[idx]) pushUpdate(idx, start, end);
        if (tree[2 * idx] >= val) return bin(val, 2 * idx, start, (start + end) / 2);
        return bin(val - tree[2 * idx], (2 * idx) + 1, ((start + end) / 2) + 1, end);
    }

    int bin(int val, int idx) {
        return bin(val, idx, 1, s);
    }
};

int n, l, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> l;
    Segtree tree(n + 1);
    for (int i = 1; i <= n; i++) tree.update(i, 1);

    int start, end;
    while (m--) {
        cin >> start >> end;
        tree.rangeUpdate(start, end, 1);
        if (tree.rangeQuery(1, n) < l) {
            cout << "AC?\n";
            continue;
        }
        cout << tree.bin(l, 1) << '\n';
    }

    return 0;
}

/*
1 1 1 1 1 1
1 0 0 0 1 1
*/