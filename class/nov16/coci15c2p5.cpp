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

void addAtBIT(vi& BIT, int idx, ll diff) {
    for (int i = idx; i < BIT.size(); i += (i & -i)) {
        BIT[i] += diff;
    }
}

ll getPrefixAtBIT(vi& BIT, int idx) {
    ll res = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
		res += BIT[i];
	}
    return res;
}

ll n, p, res = 0;
vl pre(1e6 + 5), mp(1e6 + 5);
vi BIT(1e6 + 5, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    cin >> p;
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] - p;
        mp[i] = pre[i];
        if (pre[i] >= 0) res++;
    }

    // need to map pre[i] to int -> pre[i] is gonna be like 1e15 or smt stupid
    sort(mp.begin(), mp.end());
    mp.erase(unique(mp.begin(), mp.end()), mp.end());
    for (int i = 1; i <= n; i++) {
        pre[i] = upper_bound(mp.begin(), mp.end(), pre[i]) - mp.begin();
    }

    // end at i, see how many before when subtracted is >= 0 -> pre[wtv] <= pre[i]
    for (int i = 1; i <= n; i++) {
        res += getPrefixAtBIT(BIT, pre[i]);
        addAtBIT(BIT, pre[i], 1);
    }
    cout << res << endl;
    return 0;
}