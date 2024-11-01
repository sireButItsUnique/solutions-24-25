#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, s, q, x, k;
char query;
vi stallDist(1e5 + 5);
vector<set<pii>> apples(105);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> stallDist[i];
    }
    for (int i = 0; i < s; i++) {
        int stall, apple;
        cin >> stall >> apple;
        apples[apple].insert({stallDist[stall], stall});
    }
    cin >> q;

    while (q--) {
        cin >> query >> x;
        if (query == 'Q') {
            if (apples[x].empty()) {
                cout << -1 << '\n';
            } 
            else {
                cout << (*(apples[x].begin())).second << '\n';
            }
            
            continue;
        }

        cin >> k;
        if (query == 'A') {
            apples[k].insert({stallDist[x], x});
        } else if (query == 'S') {
            apples[k].erase({stallDist[x], x});
        } else if (query == 'E') {
            for (int i = 0; i < 105; i++) {
                apples[i].erase({stallDist[x], x});
            }
            stallDist[x] = k;
        }
    }
    return 0;
}