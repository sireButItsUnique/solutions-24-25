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

ll l, n;
vector<pll> events;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> n;

    for (int i = 0; i < n; i++) {
        ll start, stop;
        cin >> start >> stop;
        events.push_back({start, 1});
        events.push_back({stop, -1});
    }
    sort(events.begin(), events.end());

    ll res = events[0].first;
    ll animals = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (animals == 0) {
            res = max(res, events[i].first - events[i - 1].first);
        }
        
        animals += events[i].second;
    }
    res = max(res, l - events.back().first);
    cout << res;
    return 0;
}