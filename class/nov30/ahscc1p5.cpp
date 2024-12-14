#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pdi pair<double, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

vector<double> a(2e5 + 2), b(2e5 + 2);
int n, k;
priority_queue<pdi> pq;
double res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        res += (a[i] / b[i]);
        pq.push({((a[i] + 1) / (b[i] + 1)) - (a[i] / b[i]), i});
    }

    while (k--) {
        auto [val, i] = pq.top();
        pq.pop();
        a[i]++;
        b[i]++;
        res += val;
        pq.push({((a[i] + 1) / (b[i] + 1)) - (a[i] / b[i]), i});
    }

    std::cout << std::fixed << std::setprecision(7);
    cout << (res / n * 100) << "\n";
    return 0;
}