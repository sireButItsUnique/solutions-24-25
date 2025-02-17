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
const ll MOD = 1e9 + 7;
const ll BASE = 31;
const ll INF = 1e18;

ll N, M, X, Y, L, S;
vector<vector<pll>> adj;
vector<int> shrine_towns;

vector<ll> dijkstra_between_nodes(int start) {
    // Standard Dijkstra's algorithm to compute shortest paths from 'start'
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(N + 1, INF);
    dist[start] = 0;
    pq.push({0, start}); // {distance, node}
    
    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();
        if (cur_dist > dist[u]) continue;

        for (auto &[v, t] : adj[u]) {
            if (dist[u] + t < dist[v]) {
                dist[v] = dist[u] + t;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

ll solve() {
    // Generate a new reduced graph for shrines + X + Y
    unordered_map<int, int> index_map; // Map original nodes to indices in reduced graph
    shrine_towns.push_back(X);
    shrine_towns.push_back(Y);
    int shrine_count = shrine_towns.size();

    for (int i = 0; i < shrine_count; ++i) {
        index_map[shrine_towns[i]] = i;
    }

    vector<vector<pll>> reduced_graph(shrine_count);
    
    for (int i = 0; i < shrine_count; ++i) {
        vector<ll> dist = dijkstra_between_nodes(shrine_towns[i]);
        for (int j = 0; j < shrine_count; ++j) {
            if (i != j && dist[shrine_towns[j]] <= L) {
                reduced_graph[i].push_back({j, dist[shrine_towns[j]]});
            }
        }
    }

    // Dijkstra on reduced graph from 'X' to 'Y'
    priority_queue<vl, vector<vl>, greater<vl>> pq; // {longest, sum, node}
    vector<ll> dist(shrine_count, INF);
    int start_idx = index_map[X];
    int end_idx = index_map[Y];
    
    dist[start_idx] = 0;
    pq.push({0, 0, start_idx});

    while (!pq.empty()) {
        ll longest = pq.top()[0];
        ll sum = pq.top()[1];
        ll node = pq.top()[2];
        pq.pop();

        if (node == end_idx) return longest;

        for (auto &[v, t] : reduced_graph[node]) {
            if (sum + t < L) {
                if (t < dist[v]) {
                    dist[v] = sum + t;
                    pq.push({max(longest, t), sum + t, v});
                }
            }
        }
    }

    return -1; // If there's no path to 'Y'
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X >> Y >> L;
    adj.assign(N + 1, vector<pll>());

    for (int i = 0; i < M; i++) {
        int A, B, T;
        cin >> A >> B >> T;
        adj[A].push_back({B, T});
    }

    cin >> S;
    shrine_towns = vi(S);
    for (int i = 0; i < S; i++) {
        cin >> shrine_towns[i];
    }

    cout << solve() << "\n";
    return 0;
}
