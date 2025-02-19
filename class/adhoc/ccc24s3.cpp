#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pii>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

int n;
vi a, b;
vector<pii> rs;
vector<pii> ls;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    b = vi(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ptr1 = 0;
    for (int ptr2 = 0; ptr2 < n; ptr2++) {
        while (ptr1 < n && a[ptr1] != b[ptr2]) ptr1++;
        //cout << ptr1 << ", " << ptr2 << '\n';
        if (ptr1 >= n) {
            cout << "NO";
            return 0;
        }

        if (ptr1 != ptr2) {
            if (ptr1 > ptr2) {
                ls.push_back({ptr1, ptr2});
            } else {
                rs.push_back({ptr1, ptr2});
            }
        }
    }

    cout << "YES\n" << (rs.size() + ls.size()) << '\n';
    for (int i = rs.size() - 1; i >= 0; i--) {
        // right since ptr1 < ptr2
        cout << "R " << rs[i].first << " " << rs[i].second << '\n';
    }
    for (auto& l: ls) {
        // left since ptr1 > ptr2
        cout << "L " << l.second << " " << l.first << '\n';
    }
    return 0;
}