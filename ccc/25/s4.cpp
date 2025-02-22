#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pii>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int n, m;
vector<vector<pll>> adj;
vb visited;
ll rec(int cur, ll level) {
    if (cur == n) {
        return 0;
    }
    visited[cur] = true;
    
    ll res = 1e18;
    for (pll& neighbour: adj[cur]) {
        if (!visited[neighbour.first]) {
            res = min(res, rec(neighbour.first, neighbour.second) + abs(neighbour.second - level));
        }
    }
    return res;
}
vector<vl> dist;
vector<pll> compress;
vector<map<ll, int>> decrypt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj = vector<vector<pll>>(n + 1);
    visited = vb(n + 1, false);
    dist = vector<vl>(n + 1, vl(25, 2e18));
    decrypt = vector<map<int, int>>(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        compress.push_back({a, c});
        compress.push_back({b, c});
    }
    for (int i = 0; i < compress.size(); i++) {
        decrypt[compress[i].first][compress[i].second] = decrypt[compress[i].first].size(); // decrypt = node, level
    }

    if (m == n - 1) {
        visited[1] = true;
        cout << rec(1, 0) << '\n';
        return 0;
    }
    
    // dijkstra
    priority_queue<vl, vector<vl>, greater<vl>> pq; // {dist, level, node}
    dist[1][0] = 0;
    pq.push({0, 0, 1});
    while (pq.size()) {
        ll d = pq.top()[0];
        ll level = pq.top()[1];
        ll cur = pq.top()[2];
        //cout << "at " << cur << " with level " << level << " costing " << d << '\n';
        pq.pop();

        if (cur == n) {
            cout << d << '\n';
            return 0;
        }

        for (pll& neighbour: adj[cur]) {
            if (dist[neighbour.first][decrypt[neighbour.first][neighbour.second]] > d + abs(neighbour.second - level)) {
                dist[neighbour.first][decrypt[neighbour.first][neighbour.second]] = d + abs(neighbour.second - level);
                pq.push({dist[neighbour.first][decrypt[neighbour.first][neighbour.second]], neighbour.second, neighbour.first});
            }
        }
    }
    return 0;
}

/*
5 7
1 2 3
2 3 2
1 3 6
3 4 3
4 5 7
2 4 1
2 5 10
*/