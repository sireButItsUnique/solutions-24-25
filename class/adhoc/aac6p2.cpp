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

int n, q;

static bool cmp(pii& a, pii& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    
    vi a(n + 1, 1);
    vector<pii> friends(q);
    int k = 1;
    for (int i = 0; i < q; i++) {
        cin >> friends[i].first >> friends[i].second;
        k = max(k, friends[i].second - friends[i].first + 1);
    }
    sort(friends.begin(), friends.end(), cmp);

    int fIdx = 0;
    for (int i = 1; i <= n; i++) {
        while (fIdx < q - 1 && friends[fIdx].second < i) {
            fIdx++;
        } 
        //cout << i << ": " << friends[fIdx].first << "->" << friends[fIdx].second << '\n';
        if (fIdx < q && friends[fIdx].first < i && friends[fIdx].second >= i) {
            a[i] = a[i - 1] + 1;
            if (a[i] > k) a[i] = 1;
        } else a[i] = a[i - 1];
    }

    cout << k << '\n';
    for (int i = 1; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << a[n] << '\n';
    return 0;
}