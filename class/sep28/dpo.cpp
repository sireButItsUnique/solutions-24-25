#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcount __builtin_popcount
ll MOD = 1e9 + 7;

ll n;
vector<vi> a(22, vi(22));
int dp[21][1 << 21]; // dp[row(man)][mask] = ways

int rec(int row, int mask) {

    // dp case
    if (dp[row][mask] != -1) {
        return dp[row][mask];
    }

    // base case -> mask should ban n cols by end
    if (row == n - 1) {
        for (int i = 0; i < n; i++) {
            if (a[row][i] && !(mask & (1 << i))) {
                dp[row][mask] = 1;
                return dp[row][mask];
            }
        }
        
        dp[row][mask] = 0;
        return dp[row][mask];
    }

    // keep recing
    dp[row][mask] = 0;
    for (int i = 0; i < n; i++) {
        if (a[row][i] && !(mask & (1 << i))) {
            dp[row][mask] += rec(row + 1, mask | (1 << i));
            dp[row][mask] %= MOD;
        }
    }
    return dp[row][mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return 0;
}