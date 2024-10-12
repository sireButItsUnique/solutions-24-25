#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

int res = 0;
ll n, m;
vs a(1002);
vector<vector<int>> visited(1002, vector<int>(1002));

bool rec(int row, int col) {
    if (row) {
        if (a[row - 1][col] == '*') return false;
        if (a[row - 1][col] == '.') {
            if (!visited[row - 1][col]) {
                visited[row - 1][col] = visited[row][col];
                if (!rec(row - 1, col)) return false;
            } 
            else if (visited[row - 1][col] != visited[row][col]) return false;
        }
    }
    if (row < n - 1) {
        if (a[row + 1][col] == '*') return false;
        if (a[row + 1][col] == '.') {
            if (!visited[row + 1][col]) {
                visited[row + 1][col] = visited[row][col];
                if (!rec(row + 1, col)) return false;
            } 
            else if (visited[row + 1][col] != visited[row][col]) return false;
        }
    }
    if (col) {
        if (a[row][col - 1] == '*') return false;
        if (a[row][col - 1] == '.') {
            if (!visited[row][col - 1]) {
                visited[row][col - 1] = visited[row][col];
                if (!rec(row, col - 1)) return false;
            } 
            else if (visited[row][col - 1] != visited[row][col]) return false;
        }
    }
    if (col < m - 1) {
        if (a[row][col + 1] == '*') return false;
        if (a[row][col + 1] == '.') {
            if (!visited[row][col + 1]) {
                visited[row][col + 1] = visited[row][col];
                if (!rec(row, col + 1)) return false;
            } 
            else if (visited[row][col + 1] != visited[row][col]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int id = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                visited[i][j] = id;
                id++;
                if (a[i][j] == '.') {
                    res += rec(i, j);
                } 
            }
        }   
    }
    cout << res << endl;
    return 0;
}