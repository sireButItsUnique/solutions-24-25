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

ll n, m, k, cur, res = 0;
vi rows, cols;
char c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;
    rows = vi(m + 5, 0);
    cols = vi(n + 5, 0);
    while (k--) {
        cin >> c >> cur;
        if (c == 'C') cols[cur] = !cols[cur];
        else rows[cur] = !rows[cur];
    }

    for (int r = 1; r <= m; r++) {
        for (int c = 1; c <= n; c++) {
            //cout << r << ", " << c << ": " << (rows[r] ^ cols[c]) << endl;
            res += (rows[r] ^ cols[c]);
        }
    }
    cout << res << endl;
    return 0;
}