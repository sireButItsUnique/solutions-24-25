#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

ll n, d;
vi a, dp;
deque<pii> dq; // dq[i] = {val, idx}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;

    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //1 4 2 6 5 1 1 8 7 3 1
    // go from 1 to n, each idx is min req to get there
    dp = vi(n);
    dp[0] = a[0];
    dq.push_back({a[0], 0});
    for (int i = 1; i < n; i++) {
        ll sum = a[i];
        
        // find min from [i - d, i - 1] -> will always be front of dq
        while (dq.front().second < i - d) {
            dq.pop_front();
        }
        dp[i] = dq.front().first + a[i];

        // add dp[i] to dq
        while (dq.size() && dq.back().first >= dp[i]) {
            dq.pop_back();
        } 
        dq.push_back({dp[i], i});
    }
    
    cout << dq.back().first << endl;
    return 0; 
}