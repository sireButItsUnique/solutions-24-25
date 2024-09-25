#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int row = 0; row < n; row += (k)) {
            for (int col = 0; col < n; col += (k)) {
                cout << a[row][col];
            }
            cout << endl;
        }
    }
    return 0;
}