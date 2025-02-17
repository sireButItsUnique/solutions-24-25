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
vl psa;

ll calc(int l, int r) {
    ll seg1 = psa[l];
    ll seg2 = psa[r] - psa[l];
    ll seg3 = psa[n] - psa[r];
    ll diff = max(abs(seg1 - seg2), abs(seg2 - seg3));
    return max(diff, abs(seg1 - seg3));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n + 3, 0);
    psa = vl(n + 3, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
    }
    ll res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int lower = i + 1, upper = n;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            ll diff = calc(i, mid);
            ll nudge = calc(i, mid + 1);
            res = min(res, diff);

            // better to move right
            if (diff > nudge) {
                lower = mid + 1;
            } 
            // better to move left
            else {
                upper = mid - 1;
            }
        }
    }

    cout << res << endl;
    return 0;
}