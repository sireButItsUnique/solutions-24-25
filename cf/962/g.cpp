#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n, m, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pii> groups;

        while (m--) {
            cin >> a >> b;

            // try going forwards
            int best = b - a;
            for (int i = 0; i < groups.size(); i++) {

            }
        }
    }
    return 0;
}