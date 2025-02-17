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

int n;
set<int> s;
vi a;
vi alrCounted(1e6 + 1, 0);
vi cnt(1e6 + 1, 0);
ll res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        res += s.size();
        res -= alrCounted[a[i]];
        if (s.count(a[i])) res--;

        alrCounted[a[i]] = s.size();
        if (s.count(a[i])) alrCounted[a[i]]--;

        cnt[a[i]]++;
        if (cnt[a[i]] == 2) s.insert(a[i]);
    }
    cout << res << '\n';

    return 0;
}