#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll T;
string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> s >> t;
        int idx = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '?' || c == t[idx]) {
                res += t[idx];
                idx++;
                if (idx == t.size()) {
                    i++;
                    for (; i < s.size(); i++) {
                        if (s[i] == '?') {
                            res += "x";
                        } else {
                            res += s[i];
                        }
                    }
                    break;
                }
            } else {
                res += c;
            }
        }

        if (idx == t.size()) {
            cout << "YES" << endl << res << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}