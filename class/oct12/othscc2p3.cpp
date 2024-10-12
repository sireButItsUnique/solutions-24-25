#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll cur = 0, n, res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    while (cur + 1111 <= n) {
        cur += 1111;
        res++;
    }
    res += (n - cur);
    cout << res << endl;
    return 0;
}