#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll t;
string n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (n[0] - '0' + n[1] - '0') << endl;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}