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
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int n, k;
vi a;
vector<vector<vi>> dp;

int rec(int left, int right, int x) {
    //cout << left << ", " << right << ", " << x << endl;
    // dp case
    if (dp[left][right][x] != -1) {
        return dp[left][right][x];
    }

    // base case
    if (left > right) {
        dp[left][right][x] = 0;
        return dp[left][right][x];
    }
    if (left == right) {
        dp[left][right][x] = max(0, k - x - 1);
        return dp[left][right][x];
    }

    // keep recing
    dp[left][right][x] = INT_MAX;
    if (x >= k - 1) {
        dp[left][right][x] = rec(left + 1, right, 0);
    } else {
        dp[left][right][x] = rec(left, right, x + 1) + 1;
    }

    for (int j = left + 1; j <= right; j++) {
        if (a[j] == a[left]) {
            int merge = rec(left + 1, j - 1, 0) + rec(j, right, x + 1);
            dp[left][right][x] = min(dp[left][right][x], merge);
        }
    }
    
    return dp[left][right][x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp.resize(n + 1, vector<vi>(n + 1, vi(100, -1)));
    cout << rec(0, n - 1, 0) << endl;
    return 0;
}