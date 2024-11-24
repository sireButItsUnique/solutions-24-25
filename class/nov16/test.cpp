#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //gp_hash_table
using namespace std;
using namespace __gnu_pbds;
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

void addAtBIT(gp_hash_table<ll, int>& BIT, ll idx, ll diff) {
    for (ll i = idx; i < 1e13; i += (i & -i)) {
        BIT[i] += diff;
    }
}

ll getPrefixAtBIT(gp_hash_table<ll, int>& BIT, ll idx) {
    ll res = 0;
    for (ll i = idx; i > 0; i -= (i & -i)) {
        res += BIT[i];
	}
    return res;
}

ll n, p, res = 0;
vl pre(1e6 + 2);
gp_hash_table<ll, int> BIT;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    cin >> p;

    // need to map pre[i] to int -> pre[i] is gonna be like 1e15 or smt stupid
    // end at i, see how many before when subtracted is >= 0 -> pre[wtv] <= pre[i]
    for (int i = 0; i < n; i++) {
        pre[i] -= p;
        if (i) pre[i] += pre[i-1];

        if (pre[i] >= 0) res++;
        res += getPrefixAtBIT(BIT, pre[i] + 1e10);
        addAtBIT(BIT, pre[i] + 1e10, 1);
    }
    cout << res << endl;
    return 0;
}