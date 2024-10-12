#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

pair<ll, int> dp[(1 << 23) + 5];
deque<pair<ll, int>> minDq;

ll n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> dp[i].first;
    }

    // base case -> start at any i < k
    for (int i = 0; i < k; i++) {
        dp[i].second = -1;
        while (minDq.size() && minDq.back().first >= dp[i].first) {
            minDq.pop_back();
        }
        minDq.push_back({dp[i].first, i});
    }

    // sliding window dp
    for (int i = k; i < n; i++) {

        // if its more than k ago it wont make the jump
        while (minDq.front().second < i - k) {
            minDq.pop_front();
        }

        // choose jump
        dp[i] = {minDq.front().first + dp[i].first, minDq.front().second};

        // push cur stone
        while (minDq.size() && minDq.back().first >= dp[i].first) {
            minDq.pop_back();
        }
        minDq.push_back({dp[i].first, i});
    }

    // only jump from last k stones
    while (minDq.front().second < n - k) {
        minDq.pop_front();
    }
    cout << minDq.front().first << endl;

    // back track to find indicies
    stack<ll> st;
    ll cur = minDq.front().second;
    while (~dp[cur].second) {
        st.push(cur); 
        cur = dp[cur].second;
    }
    st.push(cur);
    while (st.size()) {
        cout << (st.top() + 1) << " ";
        st.pop();
    }
    return 0;
}