#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m;
vi roombas;
vector<vi> events; // {x, type, y} sweep left to right, add col before popping row
unordered_map<int, int> compressMap;
vi compress;
vi BIT(4e5 + 5);

void addAtBIT(vi& BIT, int idx, ll diff) {
    for (int i = idx; i < BIT.size(); i += (i & -i)) {
        BIT[i] += diff;
    }
}

ll getPrefixAtBIT(vi& BIT, int idx) {
    ll res = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
		res += BIT[i];
	}
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        compress.push_back(y);
        roombas.push_back(y);
        events.push_back({x, 1, y}); // stop, row, y
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        compress.push_back(y);
        events.push_back({x, 0, y}); // x, col, stop
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for (int i = 0; i < compress.size(); i++) {
        compressMap[compress[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        addAtBIT(BIT, compressMap[roombas[i]], 1);
    }
    sort(events.begin(), events.end());

    ll res = 0;
    for (int i = 0; i < n + m; i++) {
        if (events[i][1] == 1) {
            addAtBIT(BIT, compressMap[events[i][2]], -1);
        } else {
            res += getPrefixAtBIT(BIT, compressMap[events[i][2]]);
        }
    }
    cout << res << "\n";
    return 0;
}