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
ll MOD = 1e9 + 7;
ll BASE = 31;

/*
4 5
0 2 5
0 1 4
1 2 3
1 3 2
2 3 2
*/
ll n, m;
vector<vector<pii>> adj(20);
vector<vi> dp(20, vi(1048575, -1));
int rec(int cur, int visited) {
    //cout << "at " << cur << ": " << visited << '\n';
    
    if (~dp[cur][visited]) return dp[cur][visited];
    
    
    if (cur == n - 1) {
        dp[cur][visited] = 0;
        return dp[cur][visited];
    }
    dp[cur][visited] = -1e9;
    for (int i = 0; i < adj[cur].size(); i++) {
        pii& neighbour = adj[cur][i];
        if (((1 << neighbour.first) & visited) == 0) {
            dp[cur][visited] = max(dp[cur][visited], rec(neighbour.first, visited | (1 << neighbour.first)) + neighbour.second);
        }
    }
    return dp[cur][visited];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int s, d, l, i = 0; i < m; i++) {
        cin >> s >> d >> l;
        adj[s].push_back({d, l});
    }
    cout << rec(0, 1) << endl;
    return 0;
}