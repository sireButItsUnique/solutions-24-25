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
vi a;
string res = "";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl << "E" << endl;
        return 0;
    }

    sort(a.begin(), a.end());
    cout << a[0] << " " << a[n - 1];
    res += "BS";
    for (int i = 1; i < n / 2; i++) {
        cout << " " << a[i] << " " << a[n - i - 1];
        res += "BS";
    }
    if (n % 2) {
        cout << " " << a[n / 2];
        res += "E";
    }
    cout << endl << res << endl;

    return 0;
}