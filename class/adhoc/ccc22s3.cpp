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
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

/*
1 = 1
12 = 3
123 = 6
1234 = 10
12344 = 5 + 3 + 2 + 1 = 11
12343 = 5 + 4 + 2 + 1 = 12
12342 = 5 + 4 + 3 + 1 = 13
12341 = 5 + 4 + 3 + 2 = 14
123412 = 6 + 5 + 4 + 3 = 18 -> however many u go back is how many u add
*/
ll n, m, k;
vi a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    if (k < n) {
        cout << -1;
        return 0;
    }
    a = vi(n + 1);

    // goal is for k to be equal to n - i
    // goal variable is how much k we want to get rid of this round
    ll i = 1;
    for (; i <= m; i++) {
        
        ll reserve = n - i; // 2 -> ideally want to have 2 left after this round
        ll goal = k - reserve; 
        //cout << i << " reserve " << reserve << "; goal " << goal << '\n';
        if (goal < i) break;
        a[i] = i;
        k -= i;
    }
    for (; i <= n; i++) {
        ll reserve = n - i;
        ll goal = k - reserve; 
        //cout << i << " reserve " << reserve << "; goal " << goal << '\n';
        
        ll goBack = min(goal, m);
        a[i] = a[i - goBack];
        k -= goBack;
    }

    if (k) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}