#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

ll n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vi a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi freq = vi(n, 0);
    ll res = 0, distinct = 0;
    ll ptr1 = 0;
    for (ll ptr2 = 0; ptr2 < n; ptr2++) {
        if (!freq[a[ptr2]]) {
            distinct++;
        }
        freq[a[ptr2]]++;

        while (distinct >= k) {
            res += (n - ptr2);

            freq[a[ptr1]]--;
            if (!freq[a[ptr1]]) {
                distinct--;
            }
            ptr1++;
        }
    }
    cout << res << endl;
    return 0;
}