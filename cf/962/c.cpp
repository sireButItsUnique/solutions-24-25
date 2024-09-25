#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n, q, l, r;
string a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> q >> a >> b;
        vector<vector<int>> aPre(26, vector<int>(n + 1, 0));
        vector<vector<int>> bPre(26, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                aPre[j][i] = aPre[j][i-1];
                bPre[j][i] = bPre[j][i-1];
            }
            aPre[a[i-1] - 'a'][i]++;
            bPre[b[i-1] - 'a'][i]++;
        }

        while (q--) {
            cin >> l >> r;
            
            ll res = 0;
            for (int i = 0; i < 26; i++) {
                int aCnt = aPre[i][r] - aPre[i][l-1];
                int bCnt = bPre[i][r] - bPre[i][l-1];
                res += abs(aCnt - bCnt);
            }
            cout << (res / 2) << endl;
        }
    }
    return 0;
}