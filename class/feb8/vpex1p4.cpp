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

int n, d, x, y;
vector<vector<pll>> adj;
vector<vl> sparse;
vector<pii> days;
vl tour;
vi firstSeen;

void rec(int cur, ll dist, int parent) {
    if (firstSeen[cur] == -1) firstSeen[cur] = tour.size();
    tour.push_back(dist);
    for (pll& next: adj[cur]) {
        if (next.first == parent) continue;
        rec(next.first, dist + next.second, cur);
        tour.push_back(dist);
    }
}

void populateSparse(vector<vl>& sparse, vl& arr) {
    int log = ceil(log2(arr.size()));
    sparse = vector<vl>(log + 1, vl(arr.size(), 1e18));

    for (int i = 0; i < arr.size(); i++) {
        sparse[0][i] = arr[i];
    }
    for (int i = 1; i <= log; i++) {
        for (int j = 0; j + (1 << i) <= arr.size(); j++) {
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
}

ll querySparse(vector<vl>& sparse, int l, int r) {
    int k = floor(log2(r - l + 1));
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}

ll getDist(int u, int v) {
    int l = firstSeen[u], r = firstSeen[v];
    if (l > r) swap(l, r);
    return tour[l] + tour[r] - 2 * querySparse(sparse, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    adj.resize(n + 1);
    firstSeen.resize(n + 1, -1);
    days.resize(d);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    rec(1, 0, -1);
    populateSparse(sparse, tour);
    for (int i = 0; i < d; i++) {
        cin >> x >> y;
        days[i] = {x, y};
    }

    // state = day, node
    vector<vl> dp(d, vl(2));
    ll distBetween = getDist(days[0].first, days[0].second);
    dp[0][0] = distBetween + getDist(1, days[0].second);
    dp[0][1] = distBetween + getDist(1, days[0].first);
    
    for (int i = 1; i < d; i++) {
        
        // 3 legs every day: start -> last day, last day -> other node, other node -> end node
        distBetween = getDist(days[i].first, days[i].second);
        dp[i][0] = min(dp[i - 1][0] + getDist(days[i - 1].first, days[i].second), 
                        dp[i - 1][1] + getDist(days[i - 1].second, days[i].second));
        dp[i][0] += distBetween;
        dp[i][1] = min(dp[i - 1][0] + getDist(days[i - 1].first, days[i].first), 
                        dp[i - 1][1] + getDist(days[i - 1].second, days[i].first));
        dp[i][1] += distBetween;
    }

    cout << min(dp.back()[0], dp.back()[1]);
    return 0;
}