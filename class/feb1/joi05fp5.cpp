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

class Segtree {
public:
    vector<ll> tree, len;
    ll n; // n = size of segtree arr

    // Reserves enough space for tree
    Segtree(ll size) {
        ll s = 1;
        while (s < size) s *= 2;
        n = s;
        tree.assign(2 * n, 0);
        len.assign(2 * n, 0);
    }

    void pushUpdate(ll idx, ll l, ll r) {
        if (tree[idx] != 0) len[idx] = (r - l + 1);
        else {
            if (l == r) {
                len[idx] = 0;
            } else {
                len[idx] = len[idx * 2] + len[idx * 2 + 1];
            }
        }
    }

    void rangeUpdate(ll l, ll r, ll start, ll end, ll diff, ll idx) {

        if (r < start || l > end) return; // No overlap, don't do anything
        if (start <= l && r <= end) { // Full overlap, update & stop here 
            tree[idx] += diff;
            pushUpdate(idx, l, r);
            return;
        }

        // Else keep trickling down to children
        ll mid = (l + r) / 2;
        rangeUpdate(l, mid, start, end, diff, idx * 2);
        rangeUpdate(mid + 1, r, start, end, diff, idx * 2 + 1);
        pushUpdate(idx, l, r);
    }
};

/*
2 2
0 0 2 2
2 0 4 2
*/
int n, r;
vector<vi> xEvents;
vector<vi> yEvents;
static bool cmp(vi& a, vi& b) {
    if (a[0] == b[0]) return a[3] > b[3];
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    xEvents.resize(2 * n);
    yEvents.resize(2 * n);
    Segtree tree(10001);
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xEvents[i * 2] = {x1, y1, y2 - 1, 1};
        xEvents[i * 2 + 1] = {x2, y1, y2 - 1, -1};
        yEvents[i * 2] = {y1, x1, x2 - 1, 1};
        yEvents[i * 2 + 1] = {y2, x1, x2 - 1, -1};
    }
    sort(xEvents.begin(), xEvents.end(), cmp);
    sort(yEvents.begin(), yEvents.end(), cmp);
    ll res = 0;
    int prevX = xEvents[0][0];
    for (int i = 0; i < 2 * n; i++) {

        // calculate diff
        ll x = xEvents[i][0];
        ll dx = x - prevX;
        
        //cout << tree.len[1] << " " << dx << endl;
        res += dx * tree.len[1];
        tree.rangeUpdate(0, 10000, xEvents[i][1], xEvents[i][2], xEvents[i][3], 1);
        prevX = x;
    }

    cout << res << endl;
    if (r == 1) return 0;

    res = 0;
    Segtree line(10001);
    ll prevCnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        line.rangeUpdate(0, 10000, yEvents[i][1], yEvents[i][2], yEvents[i][3], 1);
        res += abs(line.len[1] - prevCnt);
        prevCnt = line.len[1];
    }

    line = Segtree(10001);
    prevCnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        line.rangeUpdate(0, 10000, xEvents[i][1], xEvents[i][2], xEvents[i][3], 1);
        res += abs(line.len[1] - prevCnt);
        prevCnt = line.len[1];
    }
    cout << res << endl;
    return 0;
}