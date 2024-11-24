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

int n;
ll res = 0;
vi arr;
bool sorted = false;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (!sorted) {
        sorted = true;
        res++;
        for (int i = 0; i <= n - 2; i++) {
            if (arr[i + 1] < arr[i]) swap(arr[i + 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i + 1] < arr[i]) swap(arr[i + 1], arr[i]);
        }
        for (int i = 0; i <= n - 2; i++) {
            if (arr[i + 1] < arr[i]) {
                sorted = false;
                break;
            }
        }
    }
    cout << res << '\n';
    return 0;
}