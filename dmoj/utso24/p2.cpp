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

int n, k, h;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vi pos(n, 0), neg(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h > 0)  pos[i] = h;
        else neg[i] = -1 * h;
    }

    // take from neg if more than top 2 from pos
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    int posIdx = 0;
    int negIdx = 0;
    ll res = 0;
    while (k >= 2) {
        int sum = pos[posIdx] + pos[posIdx + 1];
        if (neg[negIdx] > 0 && neg[negIdx] > sum) {
            res += neg[negIdx];
            negIdx++;
            k -= 2;
        } else if (sum > 0) {
            res += pos[posIdx];
            posIdx++;
            k--;
        } else {
            k--;
        }
    }
    if (k) res += pos[posIdx];
    cout << res;
    return 0;
}