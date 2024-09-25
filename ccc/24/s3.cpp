#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

/*
0 1 1 0
0 0 0 1
*/
ll n;
stack<pii> rightSwipes;
queue<pii> leftSwipes;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // go from left to right whilst swiping to the left
    int aIdx = 0;
    for (int bIdx = 0; bIdx < n; bIdx++) {
        while (aIdx < n && a[aIdx] != b[bIdx]) {
            aIdx++;
        }
        if (aIdx >= n) {
            cout << "NO" << endl;
            return 0;
        }
        if (aIdx != bIdx) {
            if (aIdx < bIdx) {
                rightSwipes.push({aIdx, bIdx});
            } else {
                leftSwipes.push({bIdx, aIdx});
            }
        }
        
    }
    cout << "YES" << endl << (rightSwipes.size() + leftSwipes.size()) << endl;
    while (rightSwipes.size()) {
        cout << "R " << rightSwipes.top().first << " " << rightSwipes.top().second << endl;
        rightSwipes.pop();
    }
    while (leftSwipes.size()) {
        cout << "L " << leftSwipes.front().first << " " << leftSwipes.front().second << endl;
        leftSwipes.pop();
    }
    return 0;
}