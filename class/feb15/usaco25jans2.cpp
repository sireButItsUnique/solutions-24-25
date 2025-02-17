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

int t, n, m;
vi a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m;
        a = vi(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= m;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            a.push_back(a[i] + m);
        }

        vl pre(a.size() + 1, 0);
        for (int i = 0; i < a.size(); i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        ll res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll cur = pre[i + n] - pre[i + n - (n / 2)] - pre[i + (n / 2)] + pre[i];
            res = min(res, cur);
        }

        cout << res << '\n';
    }

    return 0;
}