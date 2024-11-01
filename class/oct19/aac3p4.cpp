#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
multiset<int> s;
ll n, m, start, res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> start;
        if (~start) s.insert(start - i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> start;
        // arrive at spot at start + row
        // arrive at spot at a[row] + col
        // start + row == a[row] + col
        // start - col == a[row] - row
        if (~start) {
            auto idx = s.find(start - i);
            if (idx != s.end()) {
                res++;
                s.erase(idx);
            }
        }
    }
    cout << res << endl;
    return 0;
}