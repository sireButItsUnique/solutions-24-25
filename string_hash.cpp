#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vi powers;

/***
GENERAL HASHING 
***/
void calcHashPowers(vi& powers) {
    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++) {
		powers[i] = (powers[i - 1] * BASE) % MOD;
	}
}

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

/*** 
FOR FIXED SUBSTRING SIZE HASHING
***/
void strRollHash(vi& res, string& s, int windowSize) {
    res = vi(s.size() - windowSize + 1);

    int hash = 0;
    for (int i = 0; i < windowSize; i++) {
        hash *= BASE;
        hash %= MOD;
        hash += (s[i] - 'a' + 1);
    }
    res[0] = hash;

    for (int i = windowSize; i < s.size(); i++) {
        hash -= powers[windowSize - 1] * (s[i - windowSize] - 'a' + 1);
        while (hash < 0) {
            hash += MOD;
        }
        hash *= BASE;
        hash %= MOD;
        hash += (s[i] - 'a' + 1);

        res[i - windowSize + 1] = hash;
    }
}

/***
FOR PALINDROMES
***/
void preHash(vi& res, string& s) {
    res = vi(s.size(), s[0] - 'A' + 1);
    for (int i = 1; i < s.size(); i++) {
        res[i] = (res[i - 1] * BASE + (s[i] - 'A' + 1));
    }
}

void sufHash(vi& res, string& s) {
    res = vi(s.size(), s.back() - 'A' + 1);
    for (int i = s.size() - 2; i >= 0; i--) {
        res[i] = (res[i + 1] * BASE + (s[i] - 'A' + 1));
    }
}

ll subPreHash(vi& strHash, int left, int right) {
    if (!left) {
        return strHash[right];
    }
    ll res = (strHash[right] - ((strHash[left - 1] * powers[right - left + 1])));
    return res;
}

ll subSufHash(vi& strHash, int left, int right) {
    if (right == strHash.size() - 1) {
        return strHash[left];
    }
    ll res = (strHash[left] - ((strHash[right + 1] * powers[(right - left + 1)])));
    return res;
}