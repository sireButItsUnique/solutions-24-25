#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
int n, maxLen;
vi powers;
vector<string> x;
map<ll, int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    x = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        maxLen = max(maxLen, (int)x[i].size());
    }
    powers = vi(maxLen, 1);
    for (int i = 1; i < maxLen; i++) {
        powers[i] = (powers[i - 1] * BASE);
    }

    int res = 1;
    for (int i = 0; i < n; i++) {
        ll lHash = 0, rHash = 0;
        int high = 1;
        for (int j = 0; j < x[i].size(); j++) {
            lHash *= BASE;
            lHash += (x[i][j] - 'A' + 1);
            rHash += (x[i][x[i].size() - j - 1] - 'A' + 1) * powers[j];
            if (rHash == lHash) {
                if (dp.count(rHash) > 0) high = max(high, dp[rHash] + 1);
            }
        }
        dp[rHash] = high;
        res = max(res, high);
    }
    cout << res << endl;
    return 0;
}