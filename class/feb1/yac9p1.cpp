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

int n;
vi s, t;
vi previous;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    previous.resize(n + 1, -1);
    for (int i = 1; i < n; i++) {
        previous[s[i]] = s[i - 1];
    }
    int res = n;
    for (int i = 1; i < n; i++) {
        if (previous[t[i]] == t[i - 1]) {
            res--;
        }
    }

    cout << res << endl;
    return 0;
}