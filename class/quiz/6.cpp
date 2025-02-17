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

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi res(n + 1, 1);
    vector<pii> reqs(m, {0, 0});
    for (int i = 0; i < m; i++) {
        cin >> reqs[i].first >> reqs[i].second;
    }

    // Process them in order & try cheaping out
    sort(reqs.begin(), reqs.end());
    for (int idx = 0; idx < m; idx++) {
        pii req = reqs[idx];
        for (int i = req.first + 1; i <= req.second; i++) {
            res[i] = res[i - 1] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}