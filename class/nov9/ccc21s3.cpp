// was rly bad, just ended up using last time's sol

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

ll n;
ll res = (1 << 60);
ll rightSum = 0, leftSum = 0, curFriend = 0;
priority_queue<pii, vector<pii>, greater<pii>> crossing;
vector<vl> friends;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    friends = vector<vl>(n + 4, vl(3));
    for (int i = 0; i < n; i++) {
        cin >> friends[i][0] >> friends[i][1] >> friends[i][2];
    }

    sort(friends.begin(), friends.end());
    for (int i = 1; i < n; i++) {
        if (friends[i][0] - friends[i][2] > friends[0][0]) rightSum += friends[i][1];
    }
    for (int i = friends[0][0]; i <= friends.back()[0]; i++) {
        
    }

    return 0;
}