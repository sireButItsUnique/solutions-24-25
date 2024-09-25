#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

ll l, r, k;

ll modpow(ll a, ll b) {
    if (b < 0) return 0;
    ll res = 1;
    while (b) {
            if (b&1) res = (res*a) % MOD;
            a = a * a % MOD;
            b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r >> k;
    
    if (k >= 10) {
        cout << 0 << endl;
        return 0;
    }
    ll numPer10 = 10 - k;
    ll range = modpow(10, r-1) - modpow(10, l-1);
    if (range < 0) {
        range += MOD;
    }
    ll res = ((numPer10 * range) % MOD);
    if (!l) {
        res--;
    }
    cout << res << endl;
    return 0;
}