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

int t;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        vl a(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[i] = x + y;
        }  
        sort(a.begin(), a.end());
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(a[i-1] - a[i]);
        }
        sum += abs(a[0] - a.back());
        cout << sum << '\n';
    }
    
    return 0;
}