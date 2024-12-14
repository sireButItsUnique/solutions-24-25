#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> GoodSet;

// need three point on one row & col tgt
// for each point, do (aboved * below) * (left * right) * 2
unordered_map<int, GoodSet> rows;
unordered_map<int, GoodSet> cols;
vector<pii> points;
ll n, res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    points = vector<pii>(n);
    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        rows[y].insert(x);
        cols[x].insert(y);
        points[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        ll above = cols[points[i].first].order_of_key(points[i].second);
        ll below = cols[points[i].first].size() - above - 1;
        ll left = rows[points[i].second].order_of_key(points[i].first);
        ll right = rows[points[i].second].size() - left - 1;
        res += (2 * above * below * left * right);
    }
    cout << res << endl;
    return 0;
}