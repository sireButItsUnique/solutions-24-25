#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
ll MOD = 1000000000000099;
ll BASE = 67;
vl powers(2e5 + 5);
vl hashes;
string n, h;

void calcHashPowers(vl& powers) {
    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++) {
		powers[i] = (powers[i - 1] * BASE) % MOD;
	}
}

void strRollHash(vl& res, string& s, int windowSize) {
    res = vl(s.size() - windowSize + 1);

    ll hash = 0;
    for (int i = 0; i < windowSize; i++) {
        hash *= BASE;
        hash += (s[i] - 'a' + 1);
        hash %= MOD;
    }
    res[0] = hash;

    for (int i = windowSize; i < s.size(); i++) {
        hash -= powers[windowSize - 1] * (s[i - windowSize] - 'a' + 1);
        while (hash < 0) {
            hash += MOD;
        }
        hash *= BASE;
        hash += (s[i] - 'a' + 1);
        hash %= MOD;

        res[i - windowSize + 1] = hash;
    }
}

vi needleCnt(26, 0);
vi windowCnt(26, 0);
set<ll> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> h;
    if (n.size() > h.size()) {
        cout << 0 << endl;
        return 0;
    }

    calcHashPowers(powers);
    strRollHash(hashes, h, n.size());
    for (int i = 0; i < n.size(); i++) {
        needleCnt[n[i] - 'a']++;
        windowCnt[h[i] - 'a']++;
    }
    if (needleCnt == windowCnt) {
        //cout << "idx 0 (" << hashes[0] << ")\n";
        res.insert(hashes[0]);
    }
    for (int i = n.size(); i < h.size(); i++) {
        windowCnt[h[i - n.size()] - 'a']--;
        windowCnt[h[i] - 'a']++;
        
        if (needleCnt == windowCnt) {
            //cout << "idx " << (i - n.size() + 1) << " (" << hashes[i - n.size() + 1] << ")\n";
            res.insert(hashes[i - n.size() + 1]);
        }
    }
    cout << res.size() << endl;
    return 0;
}
