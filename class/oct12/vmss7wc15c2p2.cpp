#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 131;
vi prefixHash, suffixHash;
vi powers(25001, 1);

void preHash(vi& res, string& s) {
    res = vi(s.size(), s[0] - 'A' + 1);
    for (int i = 1; i < s.size(); i++) {
        res[i] = (res[i - 1] * BASE + (s[i] - 'A' + 1));
    }
}

void sufHash(vi& res, string& s) {
    res = vi(s.size(), s.back() - 'A' + 1);
    for (int i = s.size() - 2; i >= 0; i--) {
        res[i] = (res[i + 1] * BASE + (s[i] - 'A' + 1));
    }
}

ll subPreHash(vi& strHash, int left, int right) {
    if (!left) {
        return strHash[right];
    }
    ll res = (strHash[right] - ((strHash[left - 1] * powers[right - left + 1])));
    return res;
}

ll subSufHash(vi& strHash, int left, int right) {
    if (right == strHash.size() - 1) {
        return strHash[left];
    }
    ll res = (strHash[left] - ((strHash[right + 1] * powers[(right - left + 1)])));
    return res;
}

ll n;
string s, res;
vi odd, even;
int r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        powers[i] = (powers[i-1] * BASE);
        if (i % 2) odd.push_back(i);
        else even.push_back(i);
    }
    preHash(prefixHash, s);
    sufHash(suffixHash, s);

    int lower = 0, upper = odd.size() - 1;
    while (lower <= upper) {
        int palSize = odd[(lower + upper) >> 1];
        //cout << "at odd " << palSize << endl; 
        bool found = false;
        for (int i = 0; i <= n - palSize; i++) {
            ll h1 = subPreHash(prefixHash, i, i + palSize - 1); 
            ll h2 = subSufHash(suffixHash, i, i + palSize - 1);
            if (h1 == h2) {
                //cout << "huh " << s.substr(i, palSize) << endl;
                if (palSize > r) {
                    r = palSize;
                    res = s.substr(i, palSize);
                }
                found = true;
                break;
            }
        }

        if (found) {
            lower = (lower + upper) / 2 + 1;
        } else {
            upper = (lower + upper) / 2 - 1;
        }
    } 

    lower = 0, upper = even.size() - 1;
    while (lower <= upper) {
        int palSize = even[(lower + upper) >> 1];
        //cout << "at odd " << palSize << endl; 
        bool found = false;
        for (int i = 0; i <= n - palSize; i++) {
            ll h1 = subPreHash(prefixHash, i, i + palSize - 1); 
            ll h2 = subSufHash(suffixHash, i, i + palSize - 1);
            if (h1 == h2) {
                //cout << "huh " << s.substr(i, palSize) << endl;
                if (palSize > r) {
                    r = palSize;
                    res = s.substr(i, palSize);
                }
                found = true;
                break;
            }
        }

        if (found) {
            lower = (lower + upper) / 2 + 1;
        } else {
            upper = (lower + upper) / 2 - 1;
        }
    } 

    cout << res << endl << r << endl;
    return 0;
}