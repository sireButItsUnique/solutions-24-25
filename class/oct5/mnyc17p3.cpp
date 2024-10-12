#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vi powers, aHash, bHash;

void strHash(vi& res, string& s) {
    res = vi(s.size(), s[0] - 'A');
    for (int i = 1; i < s.size(); i++) {
        res[i] = (res[i - 1] * BASE + (s[i] - 'A')) % MOD;
    }
}

ll substrHash(vi& strHash, int left, int right) {
    if (!left) {
        return strHash[right];
    }
    ll res = (strHash[right] - ((strHash[left - 1] * powers[right - left + 1]) % MOD) + MOD) % MOD;
    return res;
}

string a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    powers = vi(max(a.size(), b.size()), 1);
    for (int i = 1; i < powers.size(); i++) {
        powers[i] = (powers[i - 1] * BASE) % MOD;
    }
    strHash(aHash, a);
    strHash(bHash, b);

    int res = -1;
    for (int i = min(b.size(), a.size()) - 1; i >= 0; i--) {
        ll aSub = substrHash(aHash, a.size() - i - 1, a.size() - 1);
        ll bSub = substrHash(bHash, 0, i);
        // cout << "a " << a.size() - i - 1 << "->" << a.size() - 1 << " = " << aSub << endl;
        // cout << "b " << 0 << "->" << i << " = " << bSub << endl;
        if (aSub == bSub) {
            res = i;
            break;
        }
    }
 
    cout << a << b.substr(res + 1, b.size() - res) << endl;
    return 0;
}