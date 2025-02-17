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

int n, q;
vi a;
vi cnt(2e5 + 5, 0);
vector<vi> queries;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a = vi(n);
    queries = vector<vi>(q, vi(3)); // queries = right, left, idx
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int wtv;
        cin >> wtv >> queries[i][1] >> queries[i][0];
        queries[i][2] = i;
    }
    return 0;
}