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
vector<vi> adj;
vi students;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    adj = vector<vi>(n + 1);
    students = vi(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    char op;
    while (q--) {
        cin >> op;
        if (op == 'U') {
            int x, k;
            cin >> x >> k;
            students[x] += k;
            continue;
        }

        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        queue<pii> q; // node, time
        vb visited(n + 1, false);
        visited[1] = true;
        q.push({1, 0});
        int res = 0;
        while(q.size()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            for (int& neighbour: adj[node]) {
                if (!visited[neighbour]) {
                    q.push({neighbour, time + 1});
                    res += (students[neighbour] * (time + 1));
                    visited[neighbour] = true;
                }
            }
        }
        cout << res << '\n';
        adj[a].pop_back();
        adj[b].pop_back();
    }
    return 0;
}