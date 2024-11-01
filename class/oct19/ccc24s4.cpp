#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vi visited(2 * 1e5 + 5, 0);
string res;
vector<vector<pii>> adj;

void rec(int cur, bool last) {
    visited[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!visited[adj[cur][i].first]) {
            if (last) {
                res[adj[cur][i].second] = 'R';
            } else {
                res[adj[cur][i].second] = 'B';
            }
            rec(adj[cur][i].first, !last);
        }
    }
}

ll n, m, u, v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    res = string(m, 'G');
    adj = vector<vector<pii>>(n + 5);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            rec(i, false);
        }
    }
    cout << res << endl;
    return 0;
}