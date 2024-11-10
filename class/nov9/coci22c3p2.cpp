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

ll n, q;
vi a, order;
set<int> rev;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a = vi(n);
    order = vi(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        order[a[i]] = i;
    }

    if (a[0] < a.back()) rev.insert(0);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) rev.insert(i);
    }
    for (int x, y, i = 0; i < q; i++) {
        cin >> x >> y;
        rev.erase((order[x] + 1) % n);
        rev.erase(order[x]);
        rev.erase((order[y] + 1) % n);
        rev.erase(order[y]);

        swap(a[order[x]], a[order[y]]);
        swap(order[x], order[y]);
        // for (int i = 0; i < n; i++) {
        //     cout << a[i] << ' ';
        // }
        // cout << '\n';
        
        if (a[order[x]] < a[(order[x] + n - 1) % n]) rev.insert(order[x]);
        if (a[(order[x] + 1) % n] < a[order[x]]) rev.insert((order[x] + 1) % n); 
        if (a[order[y]] < a[(order[y] + n - 1) % n]) rev.insert(order[y]);
        if (a[(order[y] + 1) % n] < a[order[y]]) rev.insert((order[y] + 1) % n);
        // cout << "offending indexes: ";
        // for (auto r: rev) {
        //     cout << r << " ";
        // }
        // cout << '\n';
        
        cout << ((rev.size() > 1) ? "NE": "DA") << '\n';
    }
    return 0;
}

// 2 3 4 5 1
// 2 1 4 5 3
// 2 3 4 5 1