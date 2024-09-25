#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

ll n, k;
vi a, dp;
ll res = 0;
deque<pii> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    n++;
    a = vi(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        res += a[i];
    }

    dp = vi(n);
    dp[0] = a[0];
    dq.push_back({dp[0], 0});

    // k = 2
    // 1 2 30 4 5
    // issue is dont have to take first one -> pad everything with a 0
    for (int i = 0; i < n; i++) {

        // pop expired from dq -> must delete from [i - k - 1, i - 1]
        while (dq.front().second < i - k - 1) {
            dq.pop_front();
        }

        dp[i] = dq.front().first + a[i];

        // pop all that are bigger (wont ever be considered now that dp[i] is added at the end)
        while (dq.size() && dq.back().first >= dp[i]) {
            dq.pop_back();
        }
        dq.push_back({dp[i], i});
    }

    // chose min from [n - k - 1, n - 1] -> all are valid "endpoints" for last deletion
    while (dq.front().second < n - k - 1) {
        dq.pop_front();
    }

    cout << (res - dq.front().first) << endl;
    return 0;
}