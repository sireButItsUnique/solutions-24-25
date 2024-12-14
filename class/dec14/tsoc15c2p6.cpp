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
    ll n; // n = size of segtree arr

    // Reserves enough space for tree
    Segtree(ll size) {
        ll s = 1;
        while (s < size) s *= 2;
        n = s;
        tree.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }

    void push(ll idx, ll start, ll end) {
        if (lazy[idx] != 0) {
            tree[idx] += lazy[idx]; // Apply the pending update

            if (start != end) { // Propagate to children
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }

            lazy[idx] = 0; // Clear the lazy value
        }
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    void rangeUpdate(ll l, ll r, ll diff, ll idx, ll start, ll end) {
        push(idx, start, end);

        if (start > r || end < l) return; // No overlap, don't do anything

        if (start >= l && end <= r) { // Full overlap, update & stop here 
            lazy[idx] += diff;
            push(idx, start, end);
            return;
        }

        // Else keep trickling down to children
        ll mid = (start + end) / 2;
        rangeUpdate(l, r, diff, idx * 2, start, mid);
        rangeUpdate(l, r, diff, idx * 2 + 1, mid + 1, end);

        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]); // Update current node
    }

    // idx = node in seg tree, start = idx in org array, end = idx in org array
    ll rangeQuery(ll l, ll r, ll idx, ll start, ll end) {
        push(idx, start, end);

        if (start > r || end < l) return LLONG_MAX; // No overlap, return val which won't change res

        if (start >= l && end <= r) return tree[idx]; // Full overlap, return its val

        ll mid = (start + end) / 2;
        ll leftRes = rangeQuery(l, r, idx * 2, start, mid);
        ll rightRes = rangeQuery(l, r, idx * 2 + 1, mid + 1, end);

        return min(leftRes, rightRes);
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

    ll query(ll idx) {
        return rangeQuery(idx, idx);
    }
};

int n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    Segtree tree(n + 1); 
    for (int r, i = 1; i <= n; i++) {
        cin >> r;
        tree.rangeUpdate(i, i, r);
    }
    int a, b, c;
    while (q--) {
        cin >> a >> b >> c;
        tree.rangeUpdate(a, b, -1 * c);
        cout << max(0LL, tree.rangeQuery(a, b)) << " " << max(0LL, tree.rangeQuery(1, n)) << '\n';
    }
    return 0;
}