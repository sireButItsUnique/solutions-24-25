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
/*
2 = 0
3 = 1
4 = 1
5 = 2
*/
int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vl a(n + 1, 0);
        ll total = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        total = a[n];

        // take from edges
        int k = (n - 1) / 2;
        ll sum = 0;
        for (int i = 0; i <= k; i++) {
            ll seg1 = a[i];
            ll seg2 = a[n] - a[n + i - k];
            sum = max(sum, seg1 + seg2);
        }
        cout << (total - sum) << ' ' << sum << '\n';
    }

    return 0;
}