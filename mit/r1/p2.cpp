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

int t, n;
int p, s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<int> friendLight, friendDark;
        vi oppLight, oppDark;
        for (int i = 0; i < n; i++) {
            cin >> p >> s;
            if (s) friendDark.insert(p);
            else friendLight.insert(p);
        }
        for (int i = 0; i < n; i++) {
            cin >> p >> s;
            if (s) oppDark.push_back(p);
            else oppLight.push_back(p);
        }
        sort(oppDark.rbegin(), oppDark.rend());
        sort(oppLight.rbegin(), oppLight.rend());

        // take whatever will be worse later
        for (int opp: oppDark) {

            auto dark = friendDark.lower_bound((opp + 1) / 2);
            auto light = friendLight.lower_bound(opp);
            if (dark == friendDark.end() && light == friendLight.end()) {
                cout << "NO\n";
                goto END;
            }
            if (dark == friendDark.end()) {
                friendLight.erase(light);
                continue;
            } else if (light == friendLight.end()) {
                friendDark.erase(dark);
                continue;
            }

            // should take dark unless 2 * light is smaller than it 
            if (2 * (*light) < *dark) {
                friendLight.erase(light);
            } else {
                friendDark.erase(dark);
            }
        }

        // do light
        for (int opp: oppLight) {

            auto dark = friendDark.lower_bound(opp);
            auto light = friendLight.lower_bound((opp + 1) / 2);
            if (dark == friendDark.end() && light == friendLight.end()) {
                cout << "NO\n";
                goto END;
            }
            if (dark == friendDark.end()) {
                friendLight.erase(light);
                continue;
            } else if (light == friendLight.end()) {
                friendDark.erase(dark);
                continue;
            }

            // should take smallest of 2 * light and dark
            if (2 * (*light) < *dark) {
                friendLight.erase(light);
            } else {
                friendDark.erase(dark);
            }
        }

        cout << "YES\n";
        END:;
    }

    return 0;
}