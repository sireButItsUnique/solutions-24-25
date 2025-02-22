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

ll a, b, x, y;
ll res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> x >> y;
    res += 2 * a;
    res += 2 * b;
    res += 2 * x;
    res += 2 * y;

    ll overlapw = min(a, x);
    ll overlaph = min(b, y);
    res -= 2 * max(overlapw, overlaph);
    cout << res << '\n';
    return 0;
}