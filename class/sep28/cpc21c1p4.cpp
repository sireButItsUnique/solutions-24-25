#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;

ll n, m;
vector<bool> visited(3 * 1e5 + 5, false);
vector<vector<int>> adj(3 * 1e5 + 5, vector<int>());

// once a node is visite it's dead ->
/*
if its smaller than cur, there wont be a next iteration
if it/its children are bigger than cur, it won't be useful for next iteration anyway 
*/
void rec(int cur, vector<int>& reachable) {
    // cout << "at " << cur << " // " << adj[cur].size() << endl;
    visited[cur] = true;
    reachable.push_back(cur);

    // keep recing -> only touch unvisited nodes
    for (int i = 0; i < adj[cur].size(); i++) {
        int neighbour = adj[cur][i];
        if (!visited[neighbour]) {
            rec(neighbour, reachable);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        int from, to;
        cin >> to >> from;
        adj[from].push_back(to);
    }

    vector<pii> rank;
    for (int i = n; i > 0; i--) {
        if (!visited[i]) {
            vector<int> reachable;
            rec(i, reachable);

            // get res
            int res = -1;
            for (int j = 0; j < reachable.size(); j++) {
                if ((reachable[j] < i) && (reachable[j] > res)) {
                    res = reachable[j];
                }
            }
            if (res != -1) {
                rank.push_back({res, i});
            }
        }
    }
    sort(rank.begin(), rank.end());
    if (rank.size()) {
        cout << rank.back().first << " " << rank.back().second << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}