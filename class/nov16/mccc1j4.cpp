#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, r = 0;
string a;
vi res(1e6 + 5, 1e9);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a;
    if (a[0] == '1') res[0] = 0;
    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] + 1;
        if (a[i] == '1') res[i] = 0;
    }
    if (a[n - 1] == '1') res[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        res[i] = min(res[i], res[i + 1] + 1);
    }
    for (int i = 0; i < n; i++) {
        r += res[i];
    }
    cout << r << endl;
    return 0;
}