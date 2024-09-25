#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

ll n, m, k;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while (n--) {
        cin >> s;
        ll lastA = INT_MIN;
        for (int i = 0; i < m; i++) {
            if (s[i] == 'A') {
                lastA = i;
                bool collided = false;
                for (int j = 1; j <= k; j++) {
                    if (i + j == m) {
                        break;
                    }
                    if (s[i + j] == 'B') {
                        collided = true;
                        break;
                    }
                }
                // A ->; <- B
                (collided ? s[i] = 'N': s[i] = 'Y');
            } else if (s[i] == 'B') {
                if (lastA < (i - k)) {
                    s[i] = 'Y';
                } else {
                    s[i] = 'N';
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}