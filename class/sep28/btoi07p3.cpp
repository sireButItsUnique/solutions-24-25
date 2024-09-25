#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

ll n, m, c;
vi a;
deque<pii> minDq, maxDq; //dq[i] = val, idx
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> c;
    a = vi(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // edge case (m == 1)
    // if (m == 1) {
    //     for (int i = 1; i <= n; i++) {
    //         cout << i << endl;
    //     }
    //     return 0;
    // }

    // set up dq
    minDq.push_back({a[0], 0});
    maxDq.push_back({a[0], 0});
    for (int i = 1; i < m - 1; i++) {
        while (minDq.size() && a[i] <= minDq.back().first) {
            minDq.pop_back();
        }
        while (maxDq.size() && a[i] >= maxDq.back().first) {
            maxDq.pop_back();
        }
        minDq.push_back({a[i], i});
        maxDq.push_back({a[i], i});
    }

    // slide window, whilst keeping track of max/min -> dequeue
    for (int i = m - 1; i < n; i++) {
        
        // clear expired
        while (minDq.front().second <= i - m) {
            minDq.pop_front();
        }
         while (maxDq.front().second <= i - m) {
            maxDq.pop_front();
        }

        // push cur
        while (minDq.size() && a[i] <= minDq.back().first) {
            minDq.pop_back();
        }
        while (maxDq.size() && a[i] >= maxDq.back().first) {
            maxDq.pop_back();
        }
        minDq.push_back({a[i], i});
        maxDq.push_back({a[i], i});

        // valid silence
        // cout << i << ": " << maxDq.front().first << "->" << minDq.front().first << endl;
        if (maxDq.front().first - minDq.front().first <= c) {
            cout << (i - m + 2) << endl;
        }
    } 
    return 0;
}