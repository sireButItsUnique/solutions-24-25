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
1 2 2
1 2 5 0
1 2 3 0
1 2
*/
int k, n, m, start, dest;
vector<vector<vi>> adj; // adj[from][idx] = {to, time, dmg}
vector<vi> dist;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    adj = vector<vector<vi>>(n + 3);
    dist = vector<vi>(n + 3, vi(203, INT_MAX));
    for (int a, b, t, h, i = 0; i < m; i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    cin >> start >> dest;

    priority_queue<vi, vector<vi>, greater<vi>> pq; // time, dmg, cur
    pq.push({0, 0, start});
    while (pq.size()) {
        vi cur = pq.top();

        // reached dest
        if (cur[2] == dest) {
            cout << cur[0] << endl;
            return 0;
        }

        for (vi& neighbour: adj[cur[2]]) {
            int newT = neighbour[1] + cur[0];
            int newH = neighbour[2] + cur[1];

            // hull breaks
            if (newH >= k) continue;

            // add to pq
            if (dist[neighbour[0]][newH] > newT) {
                dist[neighbour[0]][newH] = newT;
                pq.push({newT, newH, neighbour[0]});
            }
        }
        pq.pop();
    }
    cout << -1 << endl;
    return 0;
}