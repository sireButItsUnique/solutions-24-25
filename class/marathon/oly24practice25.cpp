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

int n;
vector<vi> a, b;

void rotate(vector<vector<int>>& grid) {

    // Transpose the grid
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(grid[i][j], grid[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(grid[i].begin(), grid[i].end());
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                if (!b[i][j]) return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vector<vi>(n, vi(n));
    b = vector<vi>(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }


    if (check()) {
        cout << "Yes";
        return 0;
    }

    rotate(a);
    if (check()) {
        cout << "Yes";
        return 0;
    }

    rotate(a);
    if (check()) {
        cout << "Yes";
        return 0;
    }

    rotate(a);
    if (check()) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}