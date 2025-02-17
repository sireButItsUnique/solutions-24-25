#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dp;
int t;
string s1, s2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        queue<int> q;
        for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'A' && s[i + 2] == 'B') {
            string t = s;
            t[i + 1] = t[i + 2] = 'A';
            t[i] = 'B';
            if (!dp.count(t)) {
                dp.insert(t);
                int res = rec(t);
                if (res != -1)
                    return res + 1;
            }
        }
        if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'A') {
            string t = s;
            t[i] = t[i + 1] = 'A';
            t[i + 2] = 'B';
            if (!dp.count(t)) {
                dp.insert(t);
                int res = rec(t);
                if (res != -1)
                    return res + 1;
            }
        }
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'B') {
            string t = s;
            t[i] = t[i + 1] = 'B';
            t[i + 2] = 'A';
            if (!dp.count(t)) {
                dp.insert(t);
                int res = rec(t);
                if (res != -1)
                    return res + 1;
            }
        }
        if (s[i] == 'B' && s[i + 1] == 'B' && s[i + 2] == 'A') {
            string t = s;
            t[i + 1] = t[i + 2] = 'B';
            t[i] = 'A';
            if (!dp.count(t)) {
                dp.insert(t);
                int res = rec(t);
                if (res != -1)
                    return res + 1;
            }
        }
    }
    }
}
