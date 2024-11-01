#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m;
int start;
vi isPho(1e5 + 5, 0);
vb visited(1e5 + 5, 0);
vector<vi> adj(1e5 + 5);

bool mark(int cur) {
    visited[cur] = true;
    bool useful = isPho[cur];
    for (int neighbor : adj[cur]) {
        if (!visited[neighbor]) {
            if (mark(neighbor)) useful = true;
        }
    }
    isPho[cur] = useful;
    return useful;
}

int findRemote(int cur, int dist, int& curHigh, int& res) {
    if (dist > curHigh) {
        res = cur;
        curHigh = dist;
    }

    for (int i = 0; i < adj[cur].size(); i++) {
        if (isPho[adj[cur][i]] && !visited[adj[cur][i]]) {
            visited[adj[cur][i]] = true;
            findRemote(adj[cur][i], dist + 1, curHigh, res);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        isPho[tmp] = 1;
        start = tmp;
    }
    for (int i = 0; i < n - 1; i++) {
        int to, from;
        cin >> to >> from;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // mark useful nodes
    mark(start);

    // find diameter length
    visited = vb(1e5 + 5, 0);
    visited[start] = true;
    int diameter = -1;
    start = findRemote(start, 0, diameter, start);
    //cout << "diameter: " << start << "->";

    visited = vb(1e5 + 5, 0);
    visited[start] = true;
    diameter = -1;
    start = findRemote(start, 0, diameter, start);
    //cout << start << ": " << diameter << endl;

    // shortest path is thru diameter -> everything else nodecnt * 2
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += isPho[i];
    }
    cout << (diameter + 2 * (res - diameter - 1)) << endl;

    return 0;
}