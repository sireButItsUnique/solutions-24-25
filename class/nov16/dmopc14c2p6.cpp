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
ll MOD = 1e9 + 7;
ll BASE = 31;

void addAtBIT(vl& BIT, int idx, ll diff) {
    for (int i = idx; i < BIT.size(); i += (i & -i)) {
        BIT[i] += diff;
    }
}

ll getPrefixAtBIT(vl& BIT, int idx) {
    ll res = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
		res += BIT[i];
	}
    return res;
}

ll n, q;
vl BIT(1e6 + 3, 0);
vector<vi> trees(2e5 + 2); //trees[mass][i] = idx
vector<vi> queries; //queries[i] = {mass, a, b, idx}
vi res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int m, i = 1; i <= n; i++) {
        cin >> m;
        trees[m].push_back(i);
    }

    // offline processing -> sort from highest m to lowest m
    cin >> q;
    queries = vector<vi>(q);
    res = vi(q);
    for (int a, b, m, i = 0; i < q; i++) {
        cin >> a >> b >> m;
        queries.push_back({m, a + 1, b + 1, i});
    }
    sort(queries.rbegin(), queries.rend());

    // add to BIT pogressively
    for (int m = queries[0][0]; m < trees.size(); m++) {
        for (int idx: trees[m]) {
            addAtBIT(BIT, idx, m);
        }
    }
    res[queries[0][3]] = getPrefixAtBIT(BIT, queries[0][2]) - getPrefixAtBIT(BIT, queries[0][1] - 1);
    for (int i = 1; i < q; i++) {
        for (int m = queries[i][0]; m < queries[i-1][0]; m++) {
            for (int idx: trees[m]) {
                addAtBIT(BIT, idx, m);
            }
        }
        res[queries[i][3]] = getPrefixAtBIT(BIT, queries[i][2]) - getPrefixAtBIT(BIT, queries[i][1] - 1);
    }

    // cout res
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}