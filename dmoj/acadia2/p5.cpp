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

int n, m, res = 0;
vi a;
vector<vb> dp;
void rec(int idx, int cur) {

    // base case
    if (idx >= n) return;
    if (dp[idx][cur]) return;
    dp[idx][cur] = true;

    // dont take
    rec(idx + 1, cur);
    res = max(res, cur);

    // take
    int sum = cur + a[idx];
    if (sum > m) {
        if ((m - sum) % 2 == 0) {
            sum = m;
        } else {
            sum = m - 1;
        }
    }
    res = max(res, sum);
    rec(idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a = vi(n, 0);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c: s) {
            a[i] += (c - '0');
        }
    }

    // dp
    dp = vector<vb>(n, vb(m + 1, false));
    rec(0, 0);

    // print res
    string r(m, '0');
    for (int i = 0; i < res; i++) {
        r[i] = '1';
    }
    cout << r;
    return 0;
}