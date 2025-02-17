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

int n, s;
vi arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    arr = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());

    while (s--) {
        int m, c;
        cin >> m >> c;
        vi used(c);
        for (int i = 0; i < c; i++) {
            used[i] = arr[i] - m;
        }
        vi tmp(n);
        int ptr1 = 0, ptr2 = c;
        for (int i = 0; i < n; i++) {
            if (ptr1 < c && ptr2 < n) {
                if (used[ptr1] > arr[ptr2]) {
                    tmp[i] = used[ptr1];
                    ptr1++;
                } else {
                    tmp[i] = arr[ptr2];
                    ptr2++;
                }
            } else if (ptr1 < c) {
                tmp[i] = used[ptr1];
                ptr1++;
            } else {
                tmp[i] = arr[ptr2];
                ptr2++;
            }
        }
        arr = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}

/*
5 1
20 12 10 15 18
3 4
*/