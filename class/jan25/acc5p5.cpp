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

ll n;
ll res = 0;
vector<vi> adj(1e6 + 5);

ll rec(int node) {
    if (!adj[node].size()) return 1;

    vi bowls;
    for (int child : adj[node]) {
        bowls.push_back(rec(child));
    }
    sort(bowls.rbegin(), bowls.rend());
    ll cur = 0;
    for (int i = 0; i < bowls.size(); i++) {
        cur = max(cur, (ll)bowls[i] + i + 1);
    }
    res = max(res, cur);
    return cur - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }

    rec(1);

    cout << res << "\n";
    return 0;
}