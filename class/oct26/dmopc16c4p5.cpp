#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vector<vector<pii>> adj; // adj[from][i] = {pref, to}
vi res;

ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj = vector<vector<pii>>(n + 2);
    res = vi(n + 2);

    for (int i = 0; i < m; i++) {
        int from, to, pref;
        cin >> from >> to >> pref;
        adj[from].push_back({pref, to});
        adj[to].push_back({pref, from});
    }

    // dikstra
    priority_queue<pii> pq; // pq[i] = {pref, dest}
    for (pii& edge: adj[1]) {
        pq.push(edge);
        res[edge.second] = edge.first;
    }
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        // loop thru neigbours
        for (pii& edge: adj[cur.second]) {
            if (min(cur.first, edge.first) > res[edge.second]) {
                res[edge.second] = min(cur.first, edge.first);
                pq.push({res[edge.second], edge.second});
            }
        }
    }

    res[1] = 0; 
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}