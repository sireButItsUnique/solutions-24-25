#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m, j;
vector<int> mud(1e5 + 5, -1);
vector<int> dp(1e5 + 5, -1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> j;
    for (int i = 0; i < m; i++) {
        int p, t;
        cin >> p >> t;
        mud[p] = t;
    }

    deque<pii> dq; // idx, time -> min
    dq.push_back({0, 0});
    for (int i = 1; i <= n; i++) {

        // rmv if too far away
        while (dq.size() && dq.front().first < i - j) {
            dq.pop_front();
            if (dq.empty()) {
                cout << -1 << '\n';
                return 0;
            }
        }

        // update
        if (~mud[i]) dp[i] = max(dq.front().second, mud[i]);
        
        // push to back
        if (~dp[i]) {
            while (dq.size() && dq.back().second > dp[i]) {
                dq.pop_back();
            }
            dq.push_back({i, dp[i]});
        }
    }
    
    // rmv if too far away
    while (dq.size() && dq.front().first < n + 1 - j) {
        dq.pop_front();
        if (dq.empty()) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << dq.front().second;
    return 0;
}