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
vector<pii> updates;
vs grid;
vector<vb> exits;
vi res;
int good = 0;

vi dr = {1, -1, 0, 0};
vi dc = {0, 0, 1, -1};

bool check(int row, int col) {
    return ((row >= 1) && (col >= 1) && (row <= n) && (col <= n));
}
void rec(int row, int col) {
    if (exits[row][col]) return;
    exits[row][col] = true;
    good++;

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (check(nr, nc)) {
            if (grid[nr][nc] == '?') {
                rec(nr, nc);
            } else if (i == 0 && grid[nr][nc] == 'U') {
                rec(nr, nc);
            } else if (i == 1 && grid[nr][nc] == 'D') {
                rec(nr, nc);
            } else if (i == 2 && grid[nr][nc] == 'L') {
                rec(nr, nc);
            } else if (i == 3 && grid[nr][nc] == 'R') {
                rec(nr, nc);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    updates = vector<pii>(q);
    res = vi(q);
    grid = vs(n + 1, string(n + 1, '?'));
    exits = vector<vb>(n + 1, vb(n + 1, false));
    for (int i = 0; i < q; i++) {
        char t;
        cin >> updates[i].first >> updates[i].second >> t;
        grid[updates[i].first][updates[i].second] = t;
    }

    // final state
    for (int j = 1; j <= n; j++) {
        if (grid[1][j] == 'U' || grid[1][j] == '?') rec(1, j);
        if (grid[n][j] == 'D' || grid[n][j] == '?') rec(n, j);
    }
    for (int i = 1; i <= n; i++) {
        if (grid[i][1] == 'L' || grid[i][1] == '?') rec(i, 1);
        if (grid[i][n] == 'R' || grid[i][n] == '?') rec(i, n);
    }
    res[q - 1] = (n * n) - good;

    // go backwards -> can only be more goods at start
    for (int i = q - 1; i > 0; i--) {
        int row = updates[i].first;
        int col = updates[i].second;
        grid[row][col] = '?';

        for (int j = 0; j < 4; j++) {
            if (check(row + dr[j], col + dc[j]) && exits[row + dr[j]][col + dc[j]]) {
                rec(row, col);
                break;
            }
            if (!check(row + dr[j], col + dc[j])) {
                //cout << "edge " << i << '\n';
                rec(row, col);
                break;
            }
        }
        res[i - 1] = (n * n) - good;
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}