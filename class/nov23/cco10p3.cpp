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

ll n, x, r, k, numFriends = 0;
char q;
vi friends(1e6 + 5, 0);
unordered_map<int, int> ratings;
vi BIT(1e8 + 5, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> q;
        if (q == 'N') {
            cin >> x >> r;
            friends[x] = r;
            ratings[r] = x;
            numFriends++;
            addAtBIT(BIT, r, 1);
        } else if (q == 'M') {
            cin >> x >> r;
            addAtBIT(BIT, friends[x], -1);
            friends[x] = r;
            ratings[r] = x;
            addAtBIT(BIT, r, 1);
        } else {
            cin >> k;
            k = numFriends - k; // k = how many people you are better than
            int lower = 1, upper = 1e8 + 3, res = 0;
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                if (getPrefixAtBIT(BIT, mid) > k) {
                    upper = mid;
                } else {
                    res = max(res, mid);
                    lower = mid + 1;
                }
            }
            cout << ratings[res + 1] << '\n';
        }
    }
    return 0;
}