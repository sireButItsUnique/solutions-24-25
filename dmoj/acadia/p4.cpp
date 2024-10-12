#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, q, idx, x;
vi a;
set<int> errors;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) errors.insert(i);
    }
    if (a[0] < a.back()) errors.insert(0);
    //cout << errors.size() << " errors" << endl;
    while (q--) {
        cin >> idx >> x;
        idx--;
        a[idx] = x;

        errors.erase(idx);
        errors.erase((idx + 1) % n);
        //cout << " started " << errors.size() << endl;
        if (a[idx] < a[(idx + n - 1) % n]) errors.insert(idx);
        if (a[idx] > a[(idx + 1) % n]) errors.insert((idx + 1) % n);

        //cout << errors.size() << " errors" << endl;
        if (errors.size() > 1) {
            cout << -1 << endl;
            continue;
        }

        if (!errors.size()) {
            cout << 0 << endl;
            continue;
        }

        cout << min((ll)*(errors.begin()), n - *errors.begin()) << endl;
    }
    return 0;
}