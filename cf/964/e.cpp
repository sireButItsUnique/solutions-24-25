#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, r, l;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> l >> r;
        ll res = 0;

        // gets l + 1 to original number
        ll tmpL = l;
        while (tmpL) {
            tmpL /= 3;
            res++;
        }
        
        // complete first 3^x
        int x = 0;
        while (++x) {
            ll left = pow(3, x - 1);
            ll right = pow(3, x) - 1;
            //cout << x << ": " << left << "->" << right << endl;

            // skip if not in bounds
            if (right < l) {
                continue;
            }

            // left edge is max(left, l)
            // right edge is min(right, r)
            left = max(left, l);
            right = min(right, r);
            res += ((right - left + 1) * x);

            // exit if `right` goes over
            if (right >= r) {
                break;
            }
        }

        cout << res << endl;
    }
    return 0;
}