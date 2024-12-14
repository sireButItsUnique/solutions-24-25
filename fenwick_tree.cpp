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

/*** 
DO NOT USE IDX 0 INSIDE BIT TREES! ADD ONE IF NECESSARY 
***/
void addAtBIT(vi& BIT, int idx, ll diff) {
    for (int i = idx; i < BIT.size(); i += (i & -i)) {
        BIT[i] += diff;
    }
}

ll getPrefixAtBIT(vi& BIT, int idx) {
    ll res = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
		res += BIT[i];
	}
    return res;
}

/*** 
CAN ONLY DO PREFIX -> NO GETTING SEGMENTS
***/
void setAtBIT(vl& BIT, int idx, ll diff) {
    while (idx < BIT.size()) {
        BIT[idx] = max(BIT[idx], diff);
        idx += (-idx & idx);
    }
}

ll getMaxAtBIT(vl& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res = max(res, BIT[idx]);
        idx -= (-idx & idx);
    }
    return res;
}

/*** 
2D -> DONT USE ROW OR COL 0
***/
void addAt2DBIT(vector<vi>& BIT, int row, int col, ll diff) {
    for (int i = row; i < BIT.size(); i += (i & -i)) {
        for (int j = col; j < BIT[0].size(); j += (j & -j)) {
            BIT[i][j] += diff;
        }
    }
}

ll getPrefixAt2DBIT(vector<vi>& BIT, int row, int col) {
    ll res = 0;
    for (int i = row; i > 0; i -= (i & -i)) {
		for(int j = col; j > 0; j -= (j &-j)) {
			res += BIT[i][j];
		}
	}
    return res;
}

ll getRectAt2DBIT(vector<vi>& BIT, int r1, int r2, int c1, int c2) {
    return getPrefixAt2DBIT(BIT, r2, c2) - getPrefixAt2DBIT(BIT, r2, c1 - 1) - getPrefixAt2DBIT(BIT, r1 - 1, c2) + getPrefixAt2DBIT(BIT, r1 - 1, c1 - 1);
}