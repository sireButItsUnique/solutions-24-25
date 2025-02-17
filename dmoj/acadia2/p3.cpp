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
vi a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool modified = false;

    // fuck this edge case
    if (!((a[1] > a[0] && a[1] > a[2]) || (a[1] < a[0] && a[1] < a[2]))) {
        a[0]--;
        if (a[1] > a[0] && a[1] > a[2]) modified = true;
        else if (a[1] < a[0] && a[1] < a[1]) modified = true;

        else {
            a[0] += 2;
            if (a[1] > a[0] && a[1] > a[2]) modified = true;
            else if (a[1] < a[0] && a[1] < a[1]) modified = true;

            else a[0]--;
        }
    }
    // do the same for last element but🖕

    // main loop
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) continue;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) continue;
        if (modified) {
            cout << -1;
            return 0;
        }
        modified = true;

        a[i]--;
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) continue;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) continue;

        a[i] += 2;
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) continue;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) continue;
        cout << -1;
        return 0;
    }
    cout << 1;
    return 0;
}