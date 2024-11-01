#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll MAX_ARR_LEN = 1e5 + 5;
void addAtBIT(vl& BIT, int idx, ll diff) {
    while (idx <= MAX_ARR_LEN) {
        BIT[idx] += diff;
        idx += (-idx & idx);
    }
}

ll getPrefixAtBIT(vl& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (-idx & idx);
    }
    return res;
}