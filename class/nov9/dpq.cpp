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

ll MAX_ARR_LEN = 2e5 + 5;
void setAtBIT(vl& BIT, int idx, ll diff) {
    while (idx <= MAX_ARR_LEN) {
        BIT[idx] = max(BIT[idx], diff);
        idx += (-idx & idx);
    }
}

ll getMaxAtBIT(vl& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res = max(res, BIT[idx]);
        idx -= (-idx & idx);
    }
    return res;
}

ll n, res = 0;
vl h, a, dp;
vl BIT(2e5 + 5, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    h = vl(n);
    a = vl(n);
    dp = vl(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i] = max height if you choose the flower
    // find highest scoring flower which is smaller than you -> transition with BIT
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        ll high = getMaxAtBIT(BIT, h[i]);
        dp[i] += high;
        setAtBIT(BIT, h[i], dp[i]);
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}