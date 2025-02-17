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
vl res;

void rec(int lower, int upper, ll cur) {
    if (lower > upper) return;
    int mid = (lower + upper) / 2;
    res[mid] = max(res[mid], cur);
    rec(lower, mid - 1, cur / 4);
    rec(mid + 1, upper, cur / 4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    res = vl(n + 5, 1);
    rec(0, n - 1, 1e10);
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}