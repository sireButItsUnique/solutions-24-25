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

// order doesnt matter -> all just flips
// do it row by row
// if flipping first row doesnt align rest, ur cooked
/*
3
1 1 0
1 1 0
0 0 0

0 0 1
0 0 1
0 0 0
 */

ll n, m = 0;
vector<vi> a;
vi flips;
queue<pii> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vector<vi>(n, vi(n));
    flips = vi(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[0][i]) {
            flips[i] = true;
            res.push({0, i + 1}); //C (i + 1)
            m++;
        }
    }
    for (int flip, i = 1; i < n; i++) {
        if (flips[0]) a[i][0] = !a[i][0];
        flip = false;
        if (a[i][0]) {
            flip = true;
            res.push({1, i + 1}); //R (i + 1)
            m++;
        }
        
        // check if impossible
        for (int j = 1; j < n; j++) {
            if (flip ^ flips[j]) a[i][j] = !a[i][j];
            if (a[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << m << '\n';
    while (res.size()) {
        if (res.front().first) {
            cout << "R ";
        } else {
            cout << "C ";
        }
        cout << res.front().second << '\n';
        res.pop();
    }
    return 0;
}