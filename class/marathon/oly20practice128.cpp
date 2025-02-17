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

int n, t, m;
vi a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t >> m;
    a = vi(n + 1, t - m);
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int winner;
        cin >> winner;
        if (a[winner] > 0) res--;
        a[winner]++;
        if (a[winner] > 0) res++;
    }
    
    cout << res;
    return 0;
}