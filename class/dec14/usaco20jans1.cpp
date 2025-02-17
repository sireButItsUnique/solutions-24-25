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
2 3 4 6 8
*/
int n, k;
vi a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a = vi(n);
    int high = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        high = max(a[i], high);
    }
    int res = 0;
    for (int berries = 1; berries <= high; berries++) {
        int filled = 0;
        for (int i = 0; i < n; i++) {
            filled += (a[i] / berries);
        }

        // all baskets filled
        if (filled >= k) {
            res = max(res, berries * (k / 2));
            continue;
        }

        // fill the rest with whats remaining
        if (filled < k / 2) continue; // will be the same as a prev ans anyway
        vi tmp = a;
        for (int i = 0; i < n; i++) {
            tmp[i] %= berries;
        }
        sort(tmp.rbegin(), tmp.rend());
        int cur = berries * (filled - (k / 2));
        for (int i = 0; i < n && filled + i < k; i++) {
            cur += tmp[i];
        }
        res = max(res, cur);
    }   

    cout << res << endl;
    return 0;
}