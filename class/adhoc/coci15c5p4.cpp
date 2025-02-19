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

ll n, x;
vi a;
vi remain;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;

    a = vi(n + 1);
    remain = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        remain[i] = i;
    }

    a[1] = n; // n = 5
    remain[n] = 0;
    int i = 2;
    for (; i < n; i++) {
        ll tall = i - 1;
        ll water = n - i; // i - 1 = tall will give n - i = water
        if (water >= x) {
            a[i] = n - x - 1;
            remain[n - x - 1] = 0;
            a[i + 1] = n - 1;
            remain[n - 1] = 0;
            i += 2;
            x = 0;
            break;
        }
        a[i] = tall;
        remain[tall] = 0;
        x -= water;
    }
    if (x > 0) {
        cout << -1;
        return 0;
    }

    sort(remain.rbegin(), remain.rend());
    int idx = 0;
    for (; i <= n; i++) {
        a[i] = remain[idx++];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

/*
water = n - i
i = n - water
tall = i - 1
tall = n - water - 1
*/