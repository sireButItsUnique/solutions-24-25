#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, a1, a2, b1, b2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        int res = max(((a1 > b1) && (a2 >= b2)), ((a1 >= b1) && (a2 > b2)));
        res += max(((a1 > b2) && (a2 >= b1)), ((a1 >= b2) && (a2 > b1)));
        cout << (2 * res) << endl;
    }
    return 0;
}