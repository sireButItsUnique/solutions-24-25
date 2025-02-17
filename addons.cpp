#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
vi powers;

int logn(double n, int base) {
    n--;
    int res = 0;
    if (n < 0) {
        return -1;
    }
    while (n) {
        n /= base;
        res++;
    }
    return res;
}

ll modpow(ll a, ll b, ll mod) {
    if (b < 0) return 0;
    ll res = 1;
    while (b) {
        if (b&1) res = (res*a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}