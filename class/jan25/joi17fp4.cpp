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

/*
dijsktra to find all shortest paths from s to t then dijsktra starting from all nodes included within a shortest path to both u and v?
*/

int n, m, s, t, u, v;
vector<vector<pii>> adj; // adj[from] = {to, cost}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t >> u >> v;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vi dist(n + 1, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // pq[i] = {dist, node}
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        if (pq.top().second == t) {
               
        }
    }

    return 0;
}