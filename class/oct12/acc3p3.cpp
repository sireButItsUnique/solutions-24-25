#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n;
vi ptrs(1e5 + 2, 0);
vs strs(1e5 + 2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string res = "";
    char lastFound = 'z';
    while (true) {
        bool smtFound = false;

        // loop thru all letters
        for (char c = lastFound; c >= 'a'; c--) {
            bool allFound = true;
            vi newPtrs(n);
            lastFound = c;
        
            // loop thru all strings & try to find
            for (int i = 0; i < n; i++) {

                bool charFound = false;
                for (int j = ptrs[i]; j < strs[i].size(); j++) {
                    if (strs[i][j] == c) {
                        charFound = true;
                        newPtrs[i] = j + 1;
                        break;
                    }
                }

                if (!charFound) {
                    allFound = false;
                    break;
                }
            }

            if (allFound) {
                res += c;
                ptrs = newPtrs;
                smtFound = true;
                break;
            }
        }
        
        if (!smtFound) break;
    }

    if (res.size()) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}