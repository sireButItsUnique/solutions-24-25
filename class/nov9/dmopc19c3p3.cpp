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

ll MAX_ARR_LEN = 3e5;
void addAtBIT(vi& BIT, int idx, ll diff) {
    while (idx <= MAX_ARR_LEN) {
        BIT[idx] += diff;
        idx += (-idx & idx);
    }
}

ll getPrefixAtBIT(vi& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (-idx & idx);
    }
    return res;
}

ll n, res = 0, sum = 0;
vi a, pre, suf;
vi BIT(3e5 + 5, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    pre = vi(n);
    suf = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += ((a[i] == 1) ? 1: -1);
    }

    pre[0] = ((a[0] == 1) ? -1: 1);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if (a[i] == 1) pre[i]--;
        else pre[i]++;
    }

    suf[n-1] = ((a[n-1] == 1) ? -1: 1);
    addAtBIT(BIT, suf[n-1] + 1.5e5, 1);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (a[i] == 1) suf[i]--;
        else suf[i]++;
        addAtBIT(BIT, suf[i] + 1.5e5, 1);
        
    }
    // cout << "suf: ";
    // for (int i = 0; i < n; i++) {
    //     cout << suf[i] << " ";
    // }
    // cout << endl;

    // count res
    res += (sum > 0);
    for (int i = 0; i < n; i++) {
        res += ((sum + pre[i]) > 0);
        res += ((sum + suf[i]) > 0);

        // use BIT instead to count number of suffixes that > -sum - pre[i]
        addAtBIT(BIT, suf[i] + 1.5e5, -1);
        int cnt = getPrefixAtBIT(BIT, 3e5) - getPrefixAtBIT(BIT, -pre[i] - sum + 1.5e5);
        res += cnt;
    }
    cout << res << '\n';

    return 0;
}