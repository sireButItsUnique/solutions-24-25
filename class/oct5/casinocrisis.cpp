#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

/*

6 7 5 3 1 2 4
6 1 3 5 7 2 4 // 1
6 1 3 5 2 7 4 // 2
6 1 3 5 2 4 7 // 3
1 6 3 5 2 4 7 // 4
1 2 5 3 6 4 7 // 5
1 2 5 3 4 6 7 // 6
1 2 3 5 4 6 7 // 7
1 2 3 4 5 6 7 // 8

6 7 5 3 1 2 4
3 1 5 6 7 2 4 // 1
1 3 5 6 7 2 4 // 2
1 6 5 3 2 7 4 // 3
1 2 3 5 6 7 4 // 4
1 2 3 6 5 4 7 // 5
1 2 3 4 5 6 7 // 6

7 5 4 6 2 3 1
1 3 4 2 6 5 7 // 1
1 3 2 4 6 5 7 // 2
1 2 3 4 6 5 7 // 3
1 2 3 4 5 6 7 // 4

go idx by idx
*/

ll n, q;
vi a, idxMap; // idxMap[val] = where in a
queue<pii> res;

void swp(int left, int right) {
    vi b(right - left + 1);
    for (int i = left; i <= right; i++) {
        b[i - left] = a[i];
        idxMap[a[i]] = i;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < (b.size() / 2); i++) {
        swap(a[idxMap[b[i]]], a[idxMap[b[b.size() - i - 1]]]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a = vi(n + 1);
    idxMap = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        while (i != a[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (a[j] == i) {
                    swp(i, j);
                    res.push({i, j});
                    // for (int d = 1; d <= n; d++) {
                    //     cout << a[d] << " ";
                    // }
                    // cout << endl;
                    break;
                }
            }
        }
    }

    cout << res.size() << endl;
    while (res.size()) {
        cout << res.front().first << " " << res.front().second << endl;
        res.pop();
    }
    return 0;
}