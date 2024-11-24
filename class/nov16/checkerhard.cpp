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

void addAt2DBIT(vector<vl>& BIT, int row, int col, ll diff) {
    for (int i = row; i < BIT.size(); i += (i & -i)) {
        for (int j = col; j < BIT[0].size(); j += (j & -j)) {
            BIT[i][j] += diff;
        }
    }
}

ll getPrefixAt2DBIT(vector<vl>& BIT, int row, int col) {
    ll res = 0;
    for (int i = row; i > 0; i -= (i & -i)) {
		for(int j = col; j > 0; j -= (j &-j)) {
			res += BIT[i][j];
		}
	}
    return res;
}

ll getRectAt2DBIT(vector<vl>& BIT, int r1, int r2, int c1, int c2) {
    return getPrefixAt2DBIT(BIT, r2, c2) - getPrefixAt2DBIT(BIT, r2, c1 - 1) - getPrefixAt2DBIT(BIT, r1 - 1, c2) + getPrefixAt2DBIT(BIT, r1 - 1, c1 - 1);
}

vector<vl> blackBIT(3002, vl(3002, 0)); // odd rows = odds; even rows = even
vector<vl> whiteBIT(3002, vl(3002, 0)); // odd rows = evens; even rows = odd
ll m, n;
int ins, r1, c1, r2, c2, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    cin >> ins;
    while (ins) {
        // update
        if (ins == 1) {
            cin >> r1 >> c1 >> x;
            if ((r1 % 2) == (c1 % 2)) {
                ll diff = x - getRectAt2DBIT(blackBIT, r1, r1, c1, c1);
                addAt2DBIT(blackBIT, r1, c1, diff);
            } else {
                ll diff = x - getRectAt2DBIT(whiteBIT, r1, r1, c1, c1);
                addAt2DBIT(whiteBIT, r1, c1, diff);
            }
        } 

        // query
        else {
            cin >> r1 >> c1 >> r2 >> c2;
            if ((r1 % 2) == (c1 % 2)) {
                cout << (getRectAt2DBIT(blackBIT, r1, r2, c1, c2) - getRectAt2DBIT(whiteBIT, r1, r2, c1, c2)) << '\n';
            } else {
                cout << (getRectAt2DBIT(whiteBIT, r1, r2, c1, c2) - getRectAt2DBIT(blackBIT, r1, r2, c1, c2)) << '\n';
            }
        }
        cin >> ins;
    }
    return 0;
}

/*
90% correct guessed dog -> 90 actual dogs, 10 actual cats (x)
95% correct guessed cat -> 5  actual dogs, 95 actual cats (y)
sample contained 95 dogs, 105 cats

90x + 5y = 10x + 95y
90y = 80x
9y = 8x
8:9
*/