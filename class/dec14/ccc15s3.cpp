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
vi high(1e5 + 3);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> g >> p;
    for (int i = 0; i <= g; i++) {
        gates.insert(i);
    }
    for (int i = 0; i < p; i++) {
        cin >> high[i];
    }
    for (int i = 0; i < p; i++) {
        bool found = false;
        auto it = gates.upper_bound(high[i]);
        it--;
        //cout << "used: " << *it << "\n";
        if (*it == 0 || *it > high[i]) {
            cout << i << endl;
            return 0;
        }
        gates.erase(it);
    }
    cout << p << endl;

    return 0;
}