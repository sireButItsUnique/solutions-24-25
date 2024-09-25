#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

vector<int> front, back;
ll n, res = 0;
string key, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> key >> ans;
    front = vector<int>(n, 0);
    back = vector<int>(n, 0);

    for (int i = 1; i < n; i++) {
        front[i] = front[i-1] + (key[i-1] == ans[i-1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        back[i] = back[i+1] + (key[i + 1] == ans[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        ll score = front[i] + back[i];
        res = max(score, res);
    }
    cout << res << endl;
    return 0;
}
/*
ABCDA
ACDA

0 1 1 1 1
3 3 2 1 0
*/