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
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n;
double res = 0;
vector<pii> speed;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    speed = vector<pii>(n);
    for (int i = 0; i < n; i++) {
        cin >> speed[i].first >> speed[i].second;
    }
    sort(speed.begin(), speed.end());
    for (int i = 1; i < n; i++) {
        res = max(res, abs(speed[i].second - speed[i-1].second) / double(speed[i].first - speed[i-1].first));
    }
    cout << res << endl;
    return 0;
}