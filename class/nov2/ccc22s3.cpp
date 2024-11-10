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

// each new num adds n samples
// waste notes by adding same as last -> 1 good samples added
ll n, m, k, maxNum;
vi a(1e6 + 5);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    // edge case -> more notes than samples
    if (n > k) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        //cout << "idx " << i << ": " << k << " samples needed (goal = ";
        ll goal = k - (n - i);
        //cout << goal << ")\n";

        // waste notes
        if (k == n - i) {
            a[i] = a[i - 1];
            k--;
        }

        // build initial ascending
        else if (i <= goal && i <= m) {
            a[i] = i;
            k -= i;
            maxNum = i;
        }

        // finish up
        else {
            // go back n = add n + 1 good samples
            // however can only go back a max of maxNum - 1

            // try complete rn    
            ll goBack = goal - 1;
            if (maxNum - 1 >= goBack) {
                a[i] = a[i - goBack - 1]; 
            } else {
                goBack = maxNum - 1;
                a[i] = a[i - goBack - 1];
            }
            k -= (goBack + 1);
        }
    }

    if (k) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}