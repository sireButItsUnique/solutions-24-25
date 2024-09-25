#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

vector<vi> dp; //dp[child][candiesLeft] = ways
vi a;
ll n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    dp = vector<vi>(n, vi(k + 5, 0));
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // edge case
    if (n == 1) {
        cout << (a[0] == k) << endl;
        return 0;
    }

    // build dp
    for (int candies = 0; candies <= k; candies++) { // base case
        dp[n - 1][candies] = (a[n - 1] >= candies); 
    }
    for (int child = n - 2; child >= 0; child--) {
        vi prefix(k + 5);
        prefix[0] = dp[child + 1][0];
        for (int i = 1; i <= k; i++) {
            prefix[i] = prefix[i - 1] + dp[child + 1][i];
        }
        for (int candies = 0; candies <= k; candies++) {
            // add sum from [candies - a[child], candies] 
            dp[child][candies] = prefix[candies];
            if (a[child] < candies) {
                dp[child][candies] -= prefix[candies - a[child] - 1];
            } 
            dp[child][candies] %= MOD;

            // for (int eat = 0; eat <= min(candies, (int)a[child]); eat++) {
            //     dp[child][candies] += dp[child + 1][candies - eat];
            // }
        }
    }

    cout << dp[0][k] << endl;
    return 0;
}