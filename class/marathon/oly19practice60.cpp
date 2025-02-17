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
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(i > 0 && a[i] > a[i-1]) res += a[i];
        if(i < n-1 && a[i] >= a[i+1]) res += a[i];
    }
    cout << res << endl;

    return 0;
}