#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= x; // Subtract X from all elements
    }

    // dp[sum + 2500]: number of ways to get a sum
    vector<ll> dp(5001, 0);
    dp[2500] = 1; // Base case: one way to form sum 0

    for (int num : a) {
        vector<ll> new_dp = dp; // Copy current dp to update in the same iteration
        for (int sum = 0; sum <= 5000; sum++) {
            if (sum - num >= 0 && sum - num <= 5000) {
                new_dp[sum] += dp[sum - num];
            }
        }
        dp = new_dp;
    }

    cout << dp[2500] - 1 << endl; // Subtract 1 to exclude the empty subsequence
    return 0;
}