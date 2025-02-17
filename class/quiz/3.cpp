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

int g, p;
set<int> gates;
vector<pii> planes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g >> p;
    planes = vector<pii>(p);
    int gate, val;
    for (int i = 0; i < p; i++) {
        cin >> gate >> val;
        planes[i] = {val, gate};
    }

    // init gates & planes
    for (int i = 1; i <= g; i++) {
        gates.insert(i);
    }
    sort(planes.rbegin(), planes.rend());

    ll res = 0;
    for (int i = 0; i < p; i++) {

        // find the largest gate
        auto it = gates.upper_bound(planes[i].second);
        if (it == gates.begin()) {
            continue;
        }
        it--;

        // Add the plane's value and remove the gate from availability
        res += planes[i].first;
        gates.erase(it);
    }

    cout << res << endl;
    return 0;
}
