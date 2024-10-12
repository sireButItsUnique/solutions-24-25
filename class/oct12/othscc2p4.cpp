#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m, q;
ll k, r1, c1, r2, c2;
int tmp;
unordered_map<int, pii> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            a[tmp] = {i, j};
        }
    }

    while (q--) {
        cin >> k >> r1 >> c1 >> r2 >> c2;
        r1--; r2--; c1--; c2--;
        if (a.count(k) && a[k].first >= r1 && a[k].first <= r2 && a[k].second >= c1 && a[k].second <= c2) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}