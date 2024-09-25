#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, area;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        ll lower = 2, upper = 999;
        while (lower < upper) {
            ll m1 = lower + ((upper - lower) / 3);
            ll m2 = m1 + ((upper - lower) / 3);

            // 3/2 left
            if (upper - lower <= 2) {
                m1 = lower;
                m2 = lower + 1;
            }
            cout << "? " << m1 << " " << m2 << endl;
            cin >> area;

            // both too low
            if (area == m1 * m2) {
                lower = m2 + 1;
            }

            // in between
            else if (area == m1 * (m2 + 1)) {
                lower = m1 + 1;
                upper = m2;
            }

            // both too high
            else {
                upper = m1;
            }
        }
        cout << "! " << lower << endl;
    }
    // x = 100
    return 0;
}