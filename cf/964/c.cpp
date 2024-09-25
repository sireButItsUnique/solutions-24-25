#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t, n, s, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> s >> m;
        vector<pii> taken(n);
        for (int i = 0; i < n; i++) {
            cin >> taken[i].first >> taken[i].second;
        }
        sort(taken.begin(), taken.end());
        if (taken.back().second + s <= m) {
            cout << "YES" << endl;
            continue;
        }
        ll cur = s;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (cur <= taken[i].first) {
                cout << "YES" << endl;
                found = true;
                break;
            }
            cur = taken[i].second + s;
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}