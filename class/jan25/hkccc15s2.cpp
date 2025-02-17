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
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m;
string s, t;
ll res = 0;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    ll lenS = s.size();
    ll lenT = t.size();
    
    ll cycle = lcm(lenS, lenT);
    ll cnt = 0;
    for (int i = 0; i < lenS; i++) {
        if (s[i % lenS] == t[i % lenT]) {
            cnt++;
        }
    }
    cnt *= (n * lenS) / cycle;
    cout << cnt;
    return 0;
}

/*
bbaabb
abbb

abbbab bbabbb
bbaabb bbaabb

*/