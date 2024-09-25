#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    if (n * m == 1) {
        cout << 1 << endl;
    } else if (n >= 2 && m >= 2) {
        cout << 4 << endl;
    } else {
        cout << 2 << endl;
    }

    bool parity = false;
    if (m == 1) {
        while (n--) {
            cout << (parity + 1) << endl;
            parity = !parity;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % 2) {
                    cout << (parity + 3) << " ";
                } else {
                    cout << (parity + 1) << " ";
                }
                parity = !parity;
            }
            cout << endl;
        } 
    }
    return 0;
}