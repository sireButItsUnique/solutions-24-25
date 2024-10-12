#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

// cows = edges
// cereals = nodes
// just dfs if edges <= nodes (tree/single cycle) -> every cow will get one

// if cycle: rmv cycle & start dfs at prefered of cycle edges (cycle cow is the one at danger of getting nth) 
ll n, m;
vector<pii> cows;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cows = vector<pii>(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    return 0;
}