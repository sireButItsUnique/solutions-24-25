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

int r, c;
bool check(int row, int col) {
    if (row >= r) return false;
    if (row < 0) return false;
    if (col >= c) return false;
    if (col < 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    vs map(r); // mark as rock if visited
    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }

    queue<vi> q; // row, col, time
    queue<vi> flood; // row, col, time
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'S') {
                q.push({i, j, 0});
            } else if (map[i][j] == '*') {
                flood.push({i, j, 0});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        // flood expansion
        while (!flood.empty() && flood.front()[2] == q.front()[2]) {
            int row = flood.front()[0], col = flood.front()[1], time = flood.front()[2];
            flood.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (check(nr, nc) && map[nr][nc] == '.') {
                    map[nr][nc] = '*';
                    flood.push({nr, nc, time + 1});
                }
            }
        }

        // hedgehog movement
        int row = q.front()[0], col = q.front()[1], time = q.front()[2];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = col + dc[i];
            if (check(nr, nc)) {
                if (map[nr][nc] == 'D') {
                    cout << time + 1 << "\n"; // reached den
                    return 0;
                }
                if (map[nr][nc] == '.') {
                    map[nr][nc] = 'X'; // mark as visited -> rock
                    q.push({nr, nc, time + 1});
                }
            }
        }
    }

    cout << "KAKTUS\n";
    return 0;
}