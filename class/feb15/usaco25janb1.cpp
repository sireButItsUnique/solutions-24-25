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

int t, n, a, b;
string row;
vector<vi> grid;
vs rows;

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int cnt = 0;
        grid = vector<vi>(n, vi(n, 0));
        rows = vs(n);
        for (int i = 0; i < n; i++) {
            cin >> rows[i];
        }
        for (int i = 0; i < n; i++) {
            row = rows[i];
            for (int j = 0; j < n; j++) {
                if (row[j] == 'B') {
                    if (check(i + b, j + a)) grid[i + b][j + a]++;
                    grid[i][j]++;
                    cnt++;

                    if (grid[i][j] < 2) {
                        if (check(i - b, j - a) && rows[i - b][j - a] == 'G') {
                            cnt++;
                        } else {
                            cout << -1 << '\n';
                            goto END;
                        }
                    }
                } else if (row[j] == 'G') {
                    if (grid[i][j] == 1) continue;
                    
                    if (check(i + b, j + a)) grid[i + b][j + a] = 1;
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        END:
    }

    return 0;
}