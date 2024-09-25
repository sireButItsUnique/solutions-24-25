#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

ll m, n, u, v;
vector<bool> visited;
vector<vector<pii>> adj; // adj[from][i] = {to, idx}
string res;

void rec(int cur, bool parity) {
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!visited[adj[cur][i].first]) {
            res[adj[cur][i].second] = (parity ? 'R': 'B');
            
            visited[adj[cur][i].first] = true;
            rec(adj[cur][i].first, !parity);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    visited = vector<bool>(n, false);
    adj = vector<vector<pii>>(n);
    res = string(m, 'G');
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[--u].push_back({--v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            rec(i, false);
        }
    }
    cout << res << endl;
    return 0;
}