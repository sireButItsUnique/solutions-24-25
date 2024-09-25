#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> x;
        ll res = 0;
        
        for (ll a = 1; a < n; a++) {
            for (ll b = 1; b < n; b++) {
                ll c = n - (a * b);
                c /= (a + b);

                // doesnt fufill n or x
                if (!c) {
                    break;
                }
                if (x - a - b <= 0) {
                    break;
                }
                c = min(c, x - a - b);

                res += c;
            }
        }
        cout << res << endl;
    }
    return 0;
}