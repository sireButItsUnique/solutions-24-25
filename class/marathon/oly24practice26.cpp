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

// entire thing has to be in strict order -> topological sort, each step cannot add 2 new nodes to queue
int n, m;
vector<vi> adj;
vi indegree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj = vector<vi>(n + 1);
    indegree = vi(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    vi res(n + 1);
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) q.push(i);
    }
    while (q.size()) {
        if (q.size() != 1) {
            cout << "No";
            return 0;
        }

        int cur = q.front();
        q.pop();
        res[cur] = idx;
        idx++;

        for (int neighbour: adj[cur]) {
            indegree[neighbour]--;
            if (!indegree[neighbour]) q.push(neighbour);
        } 
    }
    if (idx != n + 1) {
        cout << "No";
        return 0;
    } 
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}