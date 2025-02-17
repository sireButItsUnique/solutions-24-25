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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ll sum = 0;
        for (char c: x) {
            sum += (c - '0');
        }
        if (sum % 3 == 0) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}