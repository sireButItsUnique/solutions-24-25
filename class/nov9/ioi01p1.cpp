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

ll MAX_ARR_LEN = 2025;
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

ll ins, x, y, a, X1, X2, Y1, Y2, s;
vector<vi> BITs(1030, vi(1030, 0));
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> ins;
    while (ins != 3) {
        if (ins == 0) {
            cin >> s;
        } else if (ins == 1) {
            cin >> x >> y >> a;
            addAtBIT(BITs[y], x + 1, a);
        } else if (ins == 2) {
            cin >> X1 >> Y1 >> X2 >> Y2;
            ll sum = 0;
            for (int i = Y1; i <= Y2; i++) {
                sum += getPrefixAtBIT(BITs[i], X2 + 1) - getPrefixAtBIT(BITs[i], X1);
            }
            cout << sum << '\n';
        }
        cin >> ins;
    }
    return 0;
}