#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(19);}
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if (m % n) {
        cout << (((m / n) % n + (m % n)) % n + 1);
    } else {
        cout << ((m / n) % n);
    }
    return 0;
}