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

// whenever possible dont invert, if must invert -> check next one, if bigger then go back, else go front (doesnt work)
// go by how many left are bigger/smaller? (doesnt work)
/*
7
2 1 7 4 6 3 5 
2
1 2
7 1 2
7 1 2 4
6 7 1 2 4
3 6 7 1 2 4 
3 6 7 1 2 4 5 // 1 inv (optimal)
*/

ll MAX_ARR_LEN = 5e5 + 5;
void addAtBIT(vl& BIT, int idx, ll diff) {
    while (idx <= MAX_ARR_LEN) {
        BIT[idx] += diff;
        idx += (-idx & idx);
    }
}

ll getPrefixAtBIT(vl& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (-idx & idx);
    }
    return res;
}

ll n, res = 0;
vi a(5e5 + 5);
vl cntTree(5e5 + 5, 0);
deque<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a[0];
    addAtBIT(cntTree, a[0], 1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        addAtBIT(cntTree, a[i], 1);
    }

    q.push_back(a[0]);
    addAtBIT(cntTree, a[0], -1);
    for (int i = 1; i < n - 1; i++) {
        addAtBIT(cntTree, a[i], -1);

        // if only gap of one, push greedy
        if (a[i] - a[i - 1] == 1) {
            //cout << a[i] << " to back\n";
            q.push_back(a[i]);
            continue;
        }
        if (a[i] - a[i - 1] == -1) {
            //cout << a[i] << " to front\n";
            q.push_front(a[i]);
            continue;
        }

        // more smaller than bigger -> push to front
        //cout << (getPrefixAtBIT(cntTree, a[i] - 1)) << " le than " << (a[i] - 1) << ": ";
        if (getPrefixAtBIT(cntTree, a[i] - 1) > (n - i - 1 - getPrefixAtBIT(cntTree, a[i] - 1))) {
            if (q.front() < a[i]) res++;
            q.push_front(a[i]);
            //cout << a[i] << " to front\n";
        } 
        // more bigger than smaller -> push to back
        else if (getPrefixAtBIT(cntTree, a[i] - 1) < (n - i - 1 - getPrefixAtBIT(cntTree, a[i] - 1))) {
            if (q.back() > a[i]) res++;
            q.push_back(a[i]);
            //cout << a[i] << " to back\n";
        }
        // equal -> push geedy
        else {
            if (a[i] >= q.back()) {
                //cout << "equal: " << a[i] << " to back\n";
                q.push_back(a[i]);
                continue;
            }
            if (a[i] <= q.front()) {
                //cout << "equal: " << a[i] << " to front\n";
                q.push_front(a[i]);
                continue;
            }
            res++;
            if (a[i + 1] > a[i]) q.push_back(a[i]);
            else q.push_front(a[i]);
        }
    }
    if (a.back() > q.front() && a.back() < q.back()) res++;
    cout << res << endl;
    return 0;
}