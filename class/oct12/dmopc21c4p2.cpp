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
int res = 0;
vector<bool> found(5000002, false); 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (!found[a[i]]) {
            for (int j = a[i]; j < 5000002; j += a[i]) {
                found[j] = true;
            }
            res++;
        }
    }
    cout << res << endl;
    return 0;
}