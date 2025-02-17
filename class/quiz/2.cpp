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

ll n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<vi> a(n + 1);
    map<int, set<int>> sets;
    int op, i, j;
    while (q--) {
        cin >> op >> i;
        if (op == 1) {
            cin >> j;
            a[j].push_back(i);
            sets[i].insert(j);
        } else if (op == 2) {
            sort(a[i].begin(), a[i].end());
            for (int num: a[i]) {
                cout << num << " ";
            }
            cout << '\n';
        } else {
            for (auto& num : sets[i]) {
                cout << num << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}