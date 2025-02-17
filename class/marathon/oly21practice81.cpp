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

vs grid;
vector<vb> visited;
int m, n, sr, sc, er, ec;

bool valid(int row, int col) {
    return (row >= 0 && col >= 0 && row < m && col < n);
}
vi dr = {0, 0, 1, -1, -2, -2, 2, 2, -1, -1, 1, 1};
vi dc = {-1, 1, 0, 0, -1, 1, -1, 1, -2, 2, -2, 2};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> sr >> sc >> er >> ec;
    sr--; sc--; er--; ec--;
    grid = vs(m);
    for (int i = 0; i < m; i++) {
        cin >> grid[i];
    }
    if (grid[sr][sc] == '#') {
        cout << -1;
        return 0;
    }

    visited = vector<vb>(m, vb(n, false));
    queue<vi> bfs; // row, col, steps
    bfs.push({sr, sc, 0});
    visited[sr][sc] = true;
    while (bfs.size()) {
        int r = bfs.front()[0];
        int c = bfs.front()[1];
        int steps = bfs.front()[2];
        
        bfs.pop();
        if (r == er && c == ec) {
            cout << steps;
            return 0;
        }
        for (int i = 0; i < 12; i++) {
            int row = r + dr[i];
            int col = c + dc[i];
            if (valid(row, col) && grid[row][col] != '#' && !visited[row][col]) {
                bfs.push({row, col, steps + 1});
                visited[row][col] = true;
            }
        }
    }
    cout << -1;
    return 0;
}