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

// use diff array
int n, q, s, t;
vl a;
vl diff;
ll res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> s >> t;
    a.resize(n + 1);
    diff.resize(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    s *= -1;
    t *= -1;
    for (int i = 1; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
        if (diff[i] > 0) {
            res += s * diff[i];
        } else {
            res += t * diff[i];
        }
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        
        if (diff[l] > 0) {
            res -= s * diff[l];
        } else {
            res -= t * diff[l];
        }
        diff[l] += x;
        if (diff[l] > 0) {
            res += s * diff[l];
        } else {
            res += t * diff[l];
        }

        if (r < n) {
            if (diff[r + 1] > 0) {
                res -= s * diff[r + 1];
            } else {
                res -= t * diff[r + 1];
            }
            diff[r + 1] -= x;
            if (diff[r + 1] > 0) {
                res += s * diff[r + 1];
            } else {
                res += t * diff[r + 1];
            }
        }
        
        cout << res << '\n';
    }

    return 0;
}