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

int x, y, z;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> z;
    int n;
    for (int i = 0; i < 7; i++) {
        cin >> n;
        if (n >= 100) y--;
        if (n >= 1) z--;
        x -= n;
    }
    if (x > 0 || y > 0 || z > 0) {
        cout << "REJECTED AGAIN";
        return 0;
    }
    cout << "MASTER";
    return 0;
}