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

ll n, t;
vector<vl> xEvents; // x, y1, y2, add/remove, tint
multiset<vl> yEvents; // y, add/remove, tint
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    xEvents.resize(2 * n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, tint;
        cin >> x1 >> y1 >> x2 >> y2 >> tint;
        xEvents[2 * i] = {x1, y1, y2, 1, tint};
        xEvents[2 * i + 1] = {x2, y1, y2, -1, tint};
    }
    sort(xEvents.begin(), xEvents.end());
    
    ll res = 0;
    ll prevX = xEvents[0][0];
    for (int i = 0; i < 2 * n; i++) {

        // calculate diff
        ll x = xEvents[i][0];
        ll dx = x - prevX;

        // calculate the area
        if (yEvents.size()) {
            ll prevY = (*(yEvents.begin()))[0];
            ll tint = 0;
            for (auto& yEvent : yEvents) {
                if (tint >= t) {
                    res += (yEvent[0] - prevY) * dx;
                }
                //cout << "yEvent: " << yEvent[0] << ' ' << yEvent[1] << ' ' << yEvent[2] << endl;
                if (yEvent[1] == 1) {
                    tint += yEvent[2];
                } else {
                    tint -= yEvent[2];
                }
                
                prevY = yEvent[0];
            }
        }
        
        
        // update verticle slice
        if (xEvents[i][3] == 1) {
            yEvents.insert({xEvents[i][1], 1, xEvents[i][4]});
            yEvents.insert({xEvents[i][2], -1, xEvents[i][4]});
        } else {
            yEvents.erase(yEvents.find({xEvents[i][1], 1, xEvents[i][4]}));
            yEvents.erase(yEvents.find({xEvents[i][2], -1, xEvents[i][4]}));
        }
        prevX = x;
        //cout << xEvents[i][0] << ' ' << xEvents[i][1] << ' ' << xEvents[i][2] << ' ' << xEvents[i][3] << ' ' << xEvents[i][4] << ": " << res << endl;
    }
    cout << res << endl;
    return 0;
}