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

int n, q;
vector<vector<pll>> adj;
vector<pll> tour;
vi firstSeen;
void rec(int cur, ll d, int parent) {
    if (firstSeen[cur] == -1) firstSeen[cur] = tour.size();
    tour.push_back({cur, d});
    for (pll& next: adj[cur]) {
        if (next.first == parent) continue;
        rec(next.first, d + next.second, cur);
        tour.push_back({cur, d});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj.resize(n + 1);
    firstSeen.resize(n + 1, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    rec(0, 0, -1);
    int log = ceil(log2(tour.size()));
    vector<vl> sparse(log + 1, vl(tour.size(), -1));
    for (int i = 0; i < tour.size(); i++) {
        sparse[0][i] = tour[i].second;
    }
    for (int i = 1; i <= log; i++) {
        for (int j = 0; j + (1 << i) <= tour.size(); j++) {
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        // get min dist between u and v using lca
        int l = firstSeen[u], r = firstSeen[v];
        if (l > r) swap(l, r);
        int k = floor(log2(r - l + 1)); // k = 2: 1 -> 4, 4 -> 7
        ll res = min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
        cout << tour[l].second + tour[r].second - (2 * res) << "\n";
        //cout << "rmq: " << l << "->" << (l + (1 << k) - 1) << " " << (r - (1 << k) + 1) << "->" << (r) << '\n';
    }

    return 0;
}