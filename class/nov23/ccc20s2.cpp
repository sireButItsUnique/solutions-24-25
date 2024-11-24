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

ll m, n;
vector<vi> grid(1005, vi(1005)); //-1 means visited

bool rec(int row, int col, int val) {
    //cout << "at " << row << ", " << col << ": " << val << '\n';
    if (row == m && col == n) return true;
    for (int r = 1; r <= sqrt(val); r++) {
        if (val % r) continue;
        int c = val / r;
        if (r <= m && c <= n) {
            if (~grid[r][c]) {
                int v = grid[r][c];
                grid[r][c] = -1;
                if (rec(r, c, v)) return true;
            }
        }
        
        if (r <= n && c <= m) {
            if (~grid[c][r]) {
                int v = grid[c][r];
                grid[c][r] = -1;
                if (rec(c, r, v)) return true;
            }
        }
        
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    if (rec(1, 1, grid[1][1])) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}