#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll h, v, last, cur, res = 0;
vector<ll> vert(1502), hori(1502);
unordered_map<ll, int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> v;
    if (!h || !v) {
        cout << 0 << endl;
        return 0;
    }
    cin >> hori[0];
    for (int i = 1; i < h; i++) {
        cin >> hori[i];
        for (int j = 0; j < i; j++) {
            cnt[hori[i] - hori[j]]++;
        }
    }

    cin >> vert[0];
    for (int i = 1; i < v; i++) {
        cin >> vert[i];
        for (int j = 0; j < i; j++) {
            res += cnt[vert[i] - vert[j]];
        }
    }
    cout << res << endl;
    return 0;
}