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

int t, k;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> k >> s;
        if (s[0] != 'M') {
            cout << "NO\n";
            goto END;
        }
        for (int i = 1; i < k; i++) {
            if (s[i-1] == 'M' && s[i] != 'I') {
                cout << "NO\n";
                goto END;
            }
            if (s[i-1] == 'I' && s[i] != 'T') {
                cout << "NO\n";
                goto END;
            }
            if (s[i-1] == 'T' && !(s[i] != 'M' || s[i] != 'I')) {
                cout << "NO\n";
                goto END;
            }
        }
        if (s.back() != 'T') {
            cout << "NO\n";
            goto END;
        }
        cout << "YES\n";
        END:;
    }

    return 0;
}