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

int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    ll res = 0;
    for (int i = n; i > 0; i--) {
        ll dist = i * 2;
        res += dist;
        int extra = k - 1;
        while (i > 0 && extra > 0) {
            extra--;
            i--;
        }
    }

    cout << res;

    return 0;
}