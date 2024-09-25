#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll s, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> n;
    s *= n;
    n++;
    ll res = 0;
    for (int i = 0; i <= 100; i++) {
        if ((s + i) / n >= 80) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}