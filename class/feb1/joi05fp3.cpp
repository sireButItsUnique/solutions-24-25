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
vi cur;
void rec(int n, int prev) {
    if (!n) {
        for (int i = 0; i < cur.size() - 1; i++) {
            cout << cur[i] << ' ';
        }
        cout << cur.back() << '\n';
        return;
    }
    for (int i = min(n, prev); i >= 1; i--) {
        cur.push_back(i);
        rec(n - i, i);
        cur.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rec(n, n);
    return 0;
}