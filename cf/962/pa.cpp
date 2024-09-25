#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << 1 << endl;
        } else {
            cout << ((n / 4) + (n % 4 > 0)) << endl;
        }
        
    }
    return 0;
}