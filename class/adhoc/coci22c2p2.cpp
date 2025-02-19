#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
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

ull x, y;
vs res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;

    int lastOp = 0;
    bool firstOp = true;
    ull bitThing = y;
    string op1 = "ACD";
    string op2 = "ADD";
    string op3 = "AAA";
    if (bitcnt(x) < bitcnt(y)) {
        op1 = "BCD";
        op2 = "BDD";
        op3 = "BBB";
        bitThing = x;
    }
    for (ll i = 0; i < 64; i++) {
        ull mask = (1ULL << i);
        if (mask & bitThing) {
            if (firstOp) {
                res.push_back(op1);
                firstOp = false;
            } else {
                res.push_back(op2);
            }
            lastOp = res.size();
        }
        res.push_back(op3);
    }

    cout << lastOp << '\n';
    for (int i = 0; i < lastOp; i++) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << '\n';
    }
    cout << "D";
    return 0;
}