#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, k, res = 0;
vi a, prefix;
vector<int> powers;
unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a = vi(n + 2);
    prefix = vi(n + 2, 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // get powers
    if (k == 1) {
        powers.push_back(1);
    } else {
        for (ll cur = k; cur <= 150; cur *= k) {
            powers.push_back(cur);
        }
    }
    
    // prefix sum
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] ^ a[i];
    }

    // find match for every power
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        for (ll power : powers) {
            res += m[prefix[i] ^ power];
        }
        m[prefix[i]]++;
    }

    cout << res << endl;
    return 0;
}

// https://vidsrc.cc/v2/embed/tv/tt10919420/1/1