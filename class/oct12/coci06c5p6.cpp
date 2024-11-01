#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<int>
#define vs vector<string>
#define bitcnt __builtin_popcount
int MOD = 1e9 + 7;
int BASE = 31, BASE2 = 131;
vi powers(200000, 1), powers2(200000, 1);
vi h, h2;
void strHash(vi& res, string& s, int x) {
    res = vi(s.size(), s[0] - 'a');
    for (int i = 1; i < s.size(); i++) {
        res[i] = (1LL*res[i - 1] * x % MOD + (s[i] - 'a')) % MOD;
    }
}
 
int substrHash(vi& strHash, int left, int right, vi& power) {
    if (!left) {
        return strHash[right];
    }
    int res = (strHash[right] - 1LL* strHash[left - 1] * power[right - left + 1] % MOD + MOD) % MOD;
    return res;
}
 
ll n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        powers[i] = 1LL*powers[i - 1] * BASE % MOD;
        powers2[i] = 1LL*powers2[i-1] * BASE2 % MOD;
    }
    strHash(h, s, BASE);  strHash(h2, s, BASE2);
 
    // bin search
    int lower = 1, upper = n, ans = 0;
    while (lower <= upper) {
        int len = (lower + upper) >> 1;
 
        gp_hash_table<ll, bool> mp;
        ll v1 = substrHash(h, 0, len - 1, powers), v2 = substrHash(h2, 0, len-1, powers2);
        mp[v1 << 32 ^ v2] = true;
        bool duped = false;
 
        // check for dupes
        for (int left = 1; left <= n - len; left++) {
            ll sub1 = substrHash(h, left, left + len - 1, powers), sub2 = substrHash(h2, left, left + len - 1, powers2);
            ll val = sub1 << 32 ^ sub2;
            if (mp.find(val) != mp.end()) {
                duped = true;
                break;
            }
            mp[val] = true;
        }
 
        if (duped) {
            lower = len + 1; ans = len;
        } else {
            upper = len - 1;
        }
    }
 
    cout << ans << "\n";
    return 0;
}