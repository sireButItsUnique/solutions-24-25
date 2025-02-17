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

// every color = one range -> start and end
// when paint over, update end to wtv
// all the colors that get painted over:
/*
therefore lazily set flag at start of range
1 2 1 2 3 2
1 2
1 1 1
1 1 1 2
1 1 1 2 3
1 1 1 2 2 2
*/
int n;
vi a;
unordered_map<int, pii> range;
vi paints;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (range.count(a[i]) && range[a[i]].first != -1) {
            // cannot paint if start & end covered by paint
            // set start to 
            if (range[a[i]].first >= paints[0]) {

            }
        }
        range[a[i]].push(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}