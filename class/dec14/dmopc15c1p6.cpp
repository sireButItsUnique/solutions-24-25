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

int m, n, q;
class Segtree {
public:
    vector<ll> tree, lazy;
    ll n; // n = size of segtree arr

    // Reserves enough space for tree
    Segtree(ll size) {
        ll s = 1;
        while (s < size) s *= 2;
        n = s;
        tree.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }

    void pushUpdate(ll idx, ll start, ll end) {
        if (lazy[idx] != 0) {
            tree[idx] += lazy[idx] * (end - start + 1); // Apply the pending update

            if (start != end) { // Propagate to children
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }

            lazy[idx] = 0; // Clear lazy val
        }
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    void rangeUpdate(ll l, ll r, ll diff, ll idx, ll start, ll end) {
        pushUpdate(idx, start, end);

        if (start > r || end < l) return; // No overlap, don't do anything

        if (start >= l && end <= r) { // Full overlap, update & stop here 
            lazy[idx] += diff;
            pushUpdate(idx, start, end);
            return;
        }

        // Else keep trickling down to children
        ll mid = (start + end) / 2;
        rangeUpdate(l, r, diff, idx * 2, start, mid);
        rangeUpdate(l, r, diff, idx * 2 + 1, mid + 1, end);

        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // Update current node
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    ll rangeQuery(ll l, ll r, ll idx, ll start, ll end) {
        pushUpdate(idx, start, end);

        if (start > r || end < l) return 0; // No overlap, return val which won't change res

        if (start >= l && end <= r) return tree[idx]; // Full overlap, return its val

        ll mid = (start + end) / 2;
        ll leftRes = rangeQuery(l, r, idx * 2, start, mid);
        ll rightRes = rangeQuery(l, r, idx * 2 + 1, mid + 1, end);

        return (leftRes + rightRes);
    }

    void rangeUpdate(ll l, ll r, ll diff) {
        rangeUpdate(l, r, diff, 1, 0, n - 1);
    }

    ll rangeQuery(ll l, ll r) {
        return rangeQuery(l, r, 1, 0, n - 1);
    }

    void update(ll idx, ll diff) {
        rangeUpdate(idx, idx, diff);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> q;
    Segtree tree(n + 5);
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        tree.update(i, a);
    }

    int op, l, r, x;
    while (q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            tree.rangeUpdate(l, r, x);
        } else {
            cout << (tree.rangeQuery(l, r) % m) << '\n';
        }
    }
    return 0;
}