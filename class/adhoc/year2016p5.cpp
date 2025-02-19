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
int firstbit(int x) {return 31 - __builtin_clz(x);}
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // n testers = split into (2 ^ n) groups
            // 3 testers: 1357 2367 4567 8
            int n, f;
            cin >> n >> f;
            if (n == 1) {
                cout << "0\n";
                continue;
            }
            if (f >= 31) {
                cout << "1\n";
                continue;
            }
            int tests = 1 << (int)f;
            if (tests >= n) {
                cout << "1\n";
                continue;
            }
            int groups = (1 << int(f - 1)); // have to keep one guy to manually test
            int perGroup = ceil((float)n / groups); // worst case is if guy who drank most dies
            
            cout << (perGroup - (f == 1)) << '\n';
        } else {
            int n, d;
            cin >> n >> d;
            if (n <= 1) {
                cout << "0\n";
                continue;
            }
            if (d >= n - 1) {
                cout << "1\n";
                continue;
            }
            int oneDay = ceil(log2(n));
            int maxGroupSize = (d - 1) + 1; // d - 1 days to test, but you test days + 1 cups
            int numGroups = ceil(float(n) / maxGroupSize);
            int finish = ceil(log2(numGroups)) + 1;
            int res = min(oneDay, finish);
            //cout << "one day: " << oneDay << " finish: " << finish << '\n';
            cout << res << '\n';
        }
    }

    return 0;
}

/*
TESTCASE
2
1 5 2
2 5 3

EXPECTED
3
2

TESTCASE
2
1 10 3
2 10 3

EXPECTED
3
3
*/