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

int n, t, k, v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t >> k >> v;
    vi a(n + 1, 0);
    for (int idx, i = 0; i < v; i++) {
        cin >> idx;
        a[idx] = 1;
    }

    int cur = 0, res = 0;
    for (int i = 1; i < t; i++) {
        cur += a[i];
    }
    for (int i = t; i <= n; i++) {
        cur -= a[i-t];
        cur += a[i];
        for (int j = i; cur < k && j > (i - t); j--) {
            if (!a[j]) {
                a[j] = 1;
                cur++;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}