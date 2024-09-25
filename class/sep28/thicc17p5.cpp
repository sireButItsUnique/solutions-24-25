#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

ll n, k;
vi a, freq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a = vi(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // count
    ll res = 0;
    ll ptr1 = 0;
    freq = vi(1e6 + 5, 0);
    ll distinctCnt = 0;
    for (int ptr2 = 0; ptr2 < n; ptr2++) {
        if (!freq[a[ptr2]]) {
            distinctCnt++;
        }
        freq[a[ptr2]]++;

        // add to sum & slide window
        while (distinctCnt >= k) {
            freq[a[ptr1]]--;
            if (freq[a[ptr1]] <= 0) {
                distinctCnt--;
            }
            ptr1++;

            res += (n - ptr2);
        }
    }

    cout << res << endl;
    return 0;
}