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

int n, x;
vi a;
vector<vl> dp; // idx, sum + 2500
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= x;
    }

    dp = vector<vl>(n + 1, vl(5500, 0));
    dp[0][2500] = 1;
    for (int i = 0; i < n; i++) {
        for (int sum = 0; sum <= 5000; sum++) {

            // carry forward the previous value (not including a[i])
            dp[i + 1][sum] += dp[i][sum];

            // include current a[i]
            if (sum - a[i] >= 0 && sum - a[i] <= 5000) {
                dp[i + 1][sum] += dp[i][sum - a[i]];
            }
        }
    }

    cout << dp[n][2500] - 1;
    return 0;
}