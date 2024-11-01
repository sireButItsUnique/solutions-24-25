#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
ll MAX_ARR_LEN = 1e5 + 5;
void addAtBIT(vl& BIT, int idx, ll diff) {
    while (idx <= MAX_ARR_LEN) {
        BIT[idx] += diff;
        idx += (-idx & idx);
    }
}

ll getPrefixAtBIT(vl& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (-idx & idx);
    }
    return res;
}

ll n, m, x, l, r, v;
char q;
vl arr(1e5 + 5), cntTree(1e5 + 5, 0), sumTree(1e5 + 5, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        addAtBIT(sumTree, i, arr[i]);
        addAtBIT(cntTree, arr[i], 1);
    }

    while (m--) {
        cin >> q;
        if (q == 'C') {
            cin >> x >> v;
            addAtBIT(sumTree, x, v - arr[x]);
            addAtBIT(cntTree, arr[x], -1);
            addAtBIT(cntTree, v, 1);
            arr[x] = v;
        } else if (q == 'S') {
            cin >> l >> r;
            cout << (getPrefixAtBIT(sumTree, r) - getPrefixAtBIT(sumTree, l - 1)) << '\n';
        } else if (q == 'Q') {
            cin >> v;
            cout << getPrefixAtBIT(cntTree, v) << '\n';
        }
    }
    return 0;
}