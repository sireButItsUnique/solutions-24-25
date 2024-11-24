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

ll MAX_ARR_LEN = (1 << 13) + 5;
void addAt2DBIT(vector<vi>& BIT, int row, int col, ll diff) {
    for (int i = row; i < BIT.size(); i += (i & -i)) {
        for (int j = col; j < BIT[0].size(); j += (j & -j)) {
            BIT[i][j] += diff;
        }
    }
}

ll getPrefixAt2DBIT(vector<vi>& BIT, int row, int col) {
    ll res = 0;

    for(int i = row; i > 0; i -= (i & -i)) {
		for(int j = col; j > 0; j -= (j &-j)) {
			res += BIT[i][j];
		}
	}
    return res;
}

ll getRectAt2DBIT(vector<vi>& BIT, int r1, int r2, int c1, int c2) {
    return getPrefixAt2DBIT(BIT, r2, c2) - getPrefixAt2DBIT(BIT, r2, c1 - 1) - getPrefixAt2DBIT(BIT, r1 - 1, c2) + getPrefixAt2DBIT(BIT, r1 - 1, c1 - 1);
}

ll n, q, i, j, a, b, h, ins;
vector<vi> BIT(MAX_ARR_LEN, vi(MAX_ARR_LEN, 0)); // BIT[idx][height] everything shifted by +1
vi heights(MAX_ARR_LEN);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        heights[i]++;
        addAt2DBIT(BIT, heights[i], i + 1, 1);
    }
    cin >> q;
    while (q--) {
        cin >> ins;
        if (ins == 1) {
            cin >> i >> j >> a >> b;
            a++;
            b++;
            i++;
            j++;
            cout << getRectAt2DBIT(BIT, a, b, i, j) << '\n';
        } else {
            cin >> i >> h;
            h++;
            addAt2DBIT(BIT, heights[i], i + 1, -1);
            heights[i] = h;
            addAt2DBIT(BIT, heights[i], i + 1, 1);
        }
    }
    return 0;
}