#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pii>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int n, b, idx;
ll res = 0;
vi a;
map<int, int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == b) idx = i;
    }
    a[idx] = 0;
    cnt[0]++;
    for (int i = idx + 1; i < n; i++) {
        if (a[i] > b) a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        cnt[a[i] * -1]++;
    }
    res += cnt[0];
    for (int i = idx - 1; i >= 0; i--) {
        if (a[i] > b) a[i] = a[i + 1] + 1;
        else a[i] = a[i + 1] - 1;
        res += cnt[a[i]];
    }
    cout << res << '\n';
    return 0;
}