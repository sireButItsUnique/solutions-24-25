#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vi powers(200000, 1);
vi h;
void strHash(vi& res, string& s) {
    res = vi(s.size(), s[0] - 'a');
    for (int i = 1; i < s.size(); i++) {
        res[i] = (res[i - 1] * BASE + (s[i] - 'a'));
    }
}

ll substrHash(vi& strHash, int left, int right) {
    if (!left) {
        return strHash[right];
    }
    ll res = (strHash[right] - ((strHash[left - 1] * powers[right - left + 1])));
    return res;
}

ll n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        powers[i] = powers[i - 1] * BASE;
    }
    strHash(h, s);

    // bin search
    int lower = 1, upper = n;
    while (lower < upper) {
        int len = (lower + upper) >> 1;
        
        set<ll> exists;
        exists.insert(substrHash(h, 0, len - 1));
        bool duped = false;

        // check for dupes
        for (int left = 1; left <= n - len; left++) {
            ll sub = substrHash(h, left, left + len - 1);
            if (exists.count(sub)) {
                duped = true;
                break;
            }
            exists.insert(sub);
        }

        if (duped) {
            lower = len + 1;
        } else {
            upper = len - 1;
        }
    }

    // check if final is over or fine
    unordered_set<ll> exists;
    exists.insert(substrHash(h, 0, lower - 1));
    bool duped = false;
    for (int left = 1; left <= n - lower; left++) {
        ll sub = substrHash(h, left, left + lower - 1);
        if (exists.count(sub)) {
            cout << lower << endl;
            return 0;
        }
        exists.insert(sub);
    }

    cout << lower - 1 << endl;
    return 0;
}