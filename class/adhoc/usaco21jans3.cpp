#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pii>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int n;
vpii a1;
vpii a2;
ll res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a1 = vpii(n);
    a2 = vpii(n);
    for (int i = 0; i < n; i++) {
        int cur;
        for (int j = 0; j < n; j++) {
            cin >> cur;
            if (j % 2) a1[i].first += cur;
            else a1[i].second += cur;

            if (i % 2) a2[j].first += cur;
            else a2[j].second += cur;
        }
    }

    for (int i = 0; i < n; i++) {
        res += max(a1[i].first, a1[i].second);
    }
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += max(a2[i].first, a2[i].second);
    }
    res = max(res, tmp);
    cout << res << '\n';
    return 0;
}

// first line decides it all:
/*
xoxo
oxox
xoxo
oxox

xxoo
ooxx
xxoo
ooxx

xoox
oxxo
xoox
oxxo

xxxx
oooo
xxxx
oooo

oxox
oxox
oxox
oxox

xxxo
ooox
xxxo
ooox
*/