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

ll n, res = 2e6;
vi preA, preB, preC;
string s;

int getCnt(vi& arr, int start, int size) {
    if (!size) return 0;
    size--;
    if (start + size < n) {
        if (!start) {
            return arr[start + size];
        }
        return arr[start + size] - arr[start - 1];
    }
    int res = arr.back() - arr[start - 1];
    res += arr[(start + size) % n];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();

    //building prefix sum
    preA = vi(n);
    preB = vi(n);
    preC = vi(n);
    preA[0] = (s[0] == 'A');
    preB[0] = (s[0] == 'B');
    preC[0] = (s[0] == 'C');
    //cout << preA[0] << ' ';
    for (int i = 1; i < n; i++) {
        preA[i] = preA[i - 1];
        preB[i] = preB[i - 1];
        preC[i] = preC[i - 1];
        preA[i] += (s[i] == 'A');
        preB[i] += (s[i] == 'B');
        preC[i] += (s[i] == 'C');
        //cout << preA[i] << ' ';
    }

    // where i is if section a starts at i
    for (int i = 0; i < n; i++) {
        ll cur = preA.back() - getCnt(preA, i, preA.back()); // gets how many As we're missing

        ll b = cur - min(getCnt(preA, (i + preA.back()) % n, preB.back()), getCnt(preB, i, preA.back())); // subtracts the b's we swapped out earlier
        b += preB.back() - getCnt(preB, (i + preA.back()) % n, preB.back()); // adds the b's we still need to swap
        res = min(res, b);

        ll c = cur - min(getCnt(preA, (i + preA.back()) % n, preC.back()), getCnt(preC, i, preA.back())); // subtracts the c's we swapped out earlier
        c += preC.back() - getCnt(preC, (i + preA.back()) % n, preC.back()); // adds the c's we still need to swap
        res = min(res, c); 
    }
    cout << res << '\n';
    return 0;
}

/* BABCBCACCA */
