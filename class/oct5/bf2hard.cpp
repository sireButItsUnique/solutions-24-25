#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;
string s;
ll k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> k;

    string res = s.substr(0, k);
    for (int i = 0; i <= s.size() - k; i++) {
        //cout << s.substr(i, k) << endl;
        for (int j = i; j < i + k; j++) {
            if (s[j] > res[j-i]) {
                break;
            }
            if (s[j] < res[j-i]) {
                res = s.substr(i, k);
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}