#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

/*
if odd do 
1 2 3
4 5 6
7 8 9
*/

/*
if even -> 2nd element skips (n - 1)
        -> 2nd row skips (n - 1) * rowTakes
        -> rowTakes = 2 * n - 2 
1 4 5 6 // rowTakes = 6


*/
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }

    if (n % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ((n * i) + j) << ' ';
            }
            cout << '\n';
        }
    } else {
        ll rowSkip = 0;
        for (int i = 2; i < n; i++) {
            rowSkip += (i - 1);
        }
        ll rowTakes = (rowSkip + n - 1);
        ll cur = 1;
        for (int i = 0; i < n; i++) {
            if (i == 1) cur += ((rowSkip - 1) * rowTakes);
            for (int j = 1; j <= n; j++) {
                if (j == 2) cur += (rowSkip - 1);
                cout << cur << ' ';
                cur++;
            }
            cout << '\n';
        }
    }
    
    return 0;
}