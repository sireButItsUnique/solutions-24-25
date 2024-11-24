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

ll uc, um, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> uc >> um >> k;
    cout << (max(uc, um) * k) << endl;
    return 0;
}