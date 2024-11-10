#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m, q, s1, d1, t1, s2, d2, t2;
vector<vi> adj(3e3 + 5);
vector<vi> dist(3e3 + 5, vi(3e3 + 5, 1e9));
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int a, b, i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // build dist arr
    for (int start = 1; start <= n; start++) {
        queue<pii> q;
        q.push({start, 0});
        dist[start][start] = 0;
        while (q.size()) {
            pii& cur = q.front();
            for (int i = 0; i < adj[cur.first].size(); i++) {
                int neighbour = adj[cur.first][i];
                if (dist[start][neighbour] > cur.second + 1) {
                    dist[start][neighbour] = cur.second + 1;
                    q.push({neighbour, cur.second + 1});
                }
            }
            q.pop();
        }
    }

    /*
    possible if (s1 -> a) + (b -> d1) is smaller than t1
                (s2 -> a) + (b -> d2) is smaller than t2
    (s1 -> a) + (s2 -> a) + (b -> d1) + (b -> d2) + 2 <= t1 + t2
    (s1 -> s2) + (d1 -> d2) + 2 <= t1 + t2

    */
    cin >> q;
    while (q--) {
        cin >> s1 >> d1 >> t1 >> s2 >> d2 >> t2;
        if (dist[s1][d1] <= t1 || dist[s2][d2] <= t2) {
            cout << "YES\n";
            continue;
        }
        if ((dist[s1][s2] + dist[d1][d2] + 2) <= (t1 + t2)) {
            cout << "YES\n";
            continue;
        }
        if ((dist[s1][d2] + dist[s2][d1] + 2) <= (t1 + t2)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}