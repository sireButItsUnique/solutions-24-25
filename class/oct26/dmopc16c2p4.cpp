#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

// whenever 2 & 5 reached a zero is added -> 2 way more common than 5 therefore count # of 5
// find max for b & min for a
ll a, b;
ll maxb = 0, mina = 1e10;

ll cntz(ll x) {
    ll sum = 0;
    for (ll i = 5; i <= x; i *= 5) { // x / 5^n = how many 5^n have been multiplied since its a factorial
        sum += x / i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    // max b
    ll lower = 1, upper = 1e10;
    while (lower <= upper) {
        ll mid = (lower + upper) >> 1;
        if (cntz(mid) > b) {
            upper = mid - 1;
        } else {
            maxb = max(maxb, mid);
            lower = mid + 1;
        }
    }
    
    lower = 1, upper = 1e10;
    while (lower <= upper) {
        ll mid = (lower + upper) >> 1;
        if (cntz(mid) < a) {
            lower = mid + 1;
        } else {
            mina = min(mina, mid);
            upper = mid - 1;
        }
    }
    cout << maxb - mina + 1 << endl;
    return 0;
}