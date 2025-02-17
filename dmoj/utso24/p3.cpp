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
6 1
110110

goal = create turn off chain
- continuous block of ones 01110
- alternating -> 01010

- each odd 1 block of n takes n
- each try to make even blocks into odd
- continue as normal

only impossible case is
2 0
11

0110
1110
1010
0010
0000

11011
11111
10111
10101
00101
00001
00000

1111 = 6
1011
0011
0111
0101
0001
0000

111111 = 8
101111
001111
011111
+ 5

111111 = 8
111011
+ 3
000111
+ 3
*/

int n, k;
string lights;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> lights;

    // impossible check
    vi imp = {'1', '1', '0'};
    bool impossible = true;
    if (k) impossible = false;
    if (n % 3 != 2) impossible = false;
    for (int i = 0; i < n; i++) {
        if (lights[i] != imp[i % 3]) {
            impossible = false;
            break; 
        }
    }
    if (impossible) {
        cout << -1;
        return 0;
    }


    // final run thru
    int res = 0;
    int cnt = 0;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (lights[i] == '1') cnt++;
        else if (lights[i] == '0' && cnt) {
            if (cnt % 2 == 1) {
                res += cnt;
                odd++;
            } else {
                res += cnt + 2;
                even++;
            }
            cnt = 0;
        }
    }
    if (cnt) {
        if (cnt % 2 == 1) {
            res += cnt;
            odd++;
        } else {
            res += cnt + 2;
            even++;
        }
    }

    while (k > 0 && even > 0) {
        res -= 3;
        k--;
        even--;
    }
    res -= k;
    res = max(res, 0);
    cout << res;
    return 0;
}