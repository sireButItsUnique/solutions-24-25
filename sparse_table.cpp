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

void populateSparse(vector<vl>& sparse, vl& arr) {
    int log = ceil(log2(arr.size()));
    sparse = vector<vl>(log + 1, vl(arr.size(), -1));

    for (int i = 0; i < arr.size(); i++) {
        sparse[0][i] = arr[i];
    }
    for (int i = 1; i <= log; i++) {
        for (int j = 0; j + (1 << i) <= arr.size(); j++) {
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
}

ll querySparse(vector<vl>& sparse, int l, int r) {
    int k = floor(log2(r - l + 1));
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}