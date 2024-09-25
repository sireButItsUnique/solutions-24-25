#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

ll n, q, idx, x;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll headIdx = 0;
    bool possible = false;
    int errors = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i % n] < a[i - 1]) {
            errors++;
            if (errors >= 2) {
                break;
            }
        }
    }
    if (errors < 2) {
        possible = true;
        // find head idx
        headIdx = 0;
        if (a.back() <= a[0]) {
            headIdx = a.size() - 1;
            while (headIdx >= 1 && a[headIdx] >= a[headIdx-1]) {
                headIdx--;
            }
        }
    }

    while (q--) {
        cin >> idx >> x;
        idx--;
        a[idx] = x;

        // testing possibility
        if (possible && (a[idx] <= a[(idx + 1) % n]) && ((idx ? a[idx - 1]: a.back()) <= a[idx])) {
            if (a[idx] <= a[headIdx]) {
                if ((idx + 1) % n == headIdx) {
                    headIdx = idx;
                }
            }
        } else {
            possible = false;
            errors = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i % n] < a[i - 1]) {
                    errors++;
                    if (errors >= 2) {
                        break;
                    }
                }
            }
            if (errors < 2) {
                possible = true;
                // find head idx
                headIdx = 0;
                if (a.back() <= a[0]) {
                    headIdx = a.size() - 1;
                    while (headIdx >= 1 && a[headIdx] >= a[headIdx-1]) {
                        headIdx--;
                    }
                }
            }
        }

        // cont
        if (possible) {            
            cout << min(headIdx, n - headIdx) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}