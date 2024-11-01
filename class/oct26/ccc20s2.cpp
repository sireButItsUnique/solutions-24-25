#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

vector<vector<int>> grid(1502, vector<int>(1502)); // 0 = visited
ll m, n;

bool rec(int row, int col, int val) {
    if (row == m && col == n) {
        return true;
    }
    grid[row][col] = 0;

    // get all factors
    for (int f1 = 1; f1 <= sqrt(val); f1++) {
        if (val % f1) continue;
        int f2 = val / f1;
        if (f1 <= m && f2 <= n && grid[f1][f2]) {
            if (rec(f1, f2, grid[f1][f2])) return true;
        }
        if (f2 <= m && f1 <= n && grid[f2][f1]) {
            if (rec(f2, f1, grid[f2][f1])) return true;
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

    cout << (rec(1, 1, grid[1][1]) ? "yes": "no") << endl;
    return 0;
}