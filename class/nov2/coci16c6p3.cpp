#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n;
vi res((1 << 20) + 5);
map<int, int> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vi a(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
        res[i] = a[i];
    }

    sort(a.rbegin(), a.rend());
    m[a[0]] = 0;
    m[a[1]] = a[0] != a[1];
    for (int i = 2; i < (1 << n); i++) {
        if (a[i] == a[i - 1]) continue;
        m[a[i]] = __builtin_clz(~((i - 1) << (32 - n))) + 1;
    }
    for (int i = 0; i < (1 << n); i++) {
        cout << m[res[i]] << " ";
    }
    return 0;
}