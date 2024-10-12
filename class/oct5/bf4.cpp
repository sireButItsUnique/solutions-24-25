#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

string s, t;
vi powers, sHash, tHash;

void strHash(vi& res, string& s) {
    res = vi(s.size(), s[0] - 'a');
    for (int i = 1; i < s.size(); i++) {
        res[i] = (res[i - 1] * BASE + (s[i] - 'a')) % MOD;
    }
}

ll substrHash(vi& strHash, int left, int right) {
    if (!left) {
        return strHash[right];
    }
    ll res = (strHash[right] - ((strHash[left - 1] * powers[right - left + 1]) % MOD) + MOD) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    powers = vi(s.size(), 1);
    for (int i = 1; i < s.size(); i++) {
        powers[i] = (powers[i - 1] * BASE) % MOD;
    }
    strHash(sHash, s);
    strHash(tHash, t);
    
    for (int i = 0; i <= s.size() - t.size(); i++) {
        ll sub = substrHash(sHash, i, i + t.size() - 1);
        if (sub == tHash.back()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}