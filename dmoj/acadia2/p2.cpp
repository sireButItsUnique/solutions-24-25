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

int n, k;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s;
    int conseq = 0, score = 0;
    bool perfect = false;
    for (char c: s) {
        if (c == 'P') score += 2;
        if (c == 'S') score += 1;
        if (c != 'F' && conseq >= k) {
            cout << "NO";
            return 0;
        }
        if (c == 'P' && perfect) {
            cout << "NO";
            return 0;
        }
        if (c == 'F') conseq = 0;
        perfect = (c == 'P');
        conseq += (c != 'F');
    }
    cout << "YES\n" << score;
    return 0;
}