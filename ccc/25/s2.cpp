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
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

string s;
ll c;
vector<pll> seqs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> c;
    ll curLen = 0;
    ll curIdx = 0;
    char curChar = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            curLen *= 10;
            curLen += (s[i] - '0');
        } else {
            seqs.push_back({curChar, curIdx});
            curIdx += curLen;
            curChar = s[i];
            curLen = 0;
        }
    }
    seqs.push_back({curChar, curIdx});
    curIdx += curLen;
    //cout << "len " << curIdx << '\n';

    c %= curIdx;
    //cout << "idx " << c << '\n';
    for (int i = 0; i < seqs.size() - 1; i++) {
        if (seqs[i].second <= c && seqs[i + 1].second > c) {
            cout << char(seqs[i].first) << '\n';
            return 0;
        }
    }
    cout << char(seqs.back().first) << '\n';
    return 0;
}