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

int n, m;
vector<pii> res;
queue<int> connect;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if (m == 1) {
        cout << -1;
        return 0;
    }
    res = vector<pii>(n + 1);
    for (int i = n + 1; i <= n + m; i++) {
        connect.push(i);
    }
    
    for (int i = n; i >= 1; i--) {
        int left = -1, right = -1;
        if (connect.size()) {
            left = connect.front();
            connect.pop();
        }
        if (connect.size()) {
            right = connect.front();
            connect.pop();
        } else {
            right = left + 1;
        }
        
        res[i] = {left, right};
        connect.push(i);
    }

    if (connect.size() > 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
    return 0;
}