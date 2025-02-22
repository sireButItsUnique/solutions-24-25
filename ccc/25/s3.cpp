#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vpii vector<pii>
#define bitcnt __builtin_popcount
void precise() {cout << fixed << setprecision(7);}
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n, m, q;
vector<multiset<int>> colors;
vi orgColor, orgPretty;

int secondHighest(multiset<int>& cur) {
    int high = *(cur.rbegin());
    cur.erase(cur.find(high));
    int second = *(cur.rbegin());
    cur.insert(high);
    return second;
}

void getPrettiest() {
    // only one color
    if (m == 1) {
        cout << *(colors[1].rbegin()) << '\n';
        return;
    }

    // get top two prettiest pens of each color
    ll res = 0;
    vpii ugliest;
    vpii prettiest;
    for (int i = 1; i <= m; i++) {
        if (colors[i].size() >= 2) prettiest.push_back({secondHighest(colors[i]), i});
        if (colors[i].size() <= 0) colors[i].insert(0);
        ugliest.push_back({*(colors[i].rbegin()), i});
        res += ugliest.back().first;
    }
    sort(ugliest.begin(), ugliest.end());
    sort(prettiest.rbegin(), prettiest.rend());
    
    // replace first pair
    if (prettiest.size()) {
        if (ugliest[0].second != prettiest[0].second) {
            res = max(res, res + (prettiest[0].first - ugliest[0].first));
        } 
        // replace cross pairs
        else if (prettiest.size() > 1) {
            ll tmp = 0;
            tmp = max(res, res + (prettiest[1].first - ugliest[0].first));
            tmp = max(res, res + (prettiest[0].first - ugliest[1].first));
            res = max(res, tmp);
        }
    }
    cout << res << '\n';
}

ll high = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    colors = vector<multiset<int>>(m + 5);
    orgColor = vi(n + 1);
    orgPretty = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        int c, p;
        cin >> c >> p;
        colors[c].insert(p);
        orgColor[i] = c;
        orgPretty[i] = p;
    }
    getPrettiest();


    while (q > 0) {
        int op, idx, change;
        cin >> op >> idx >> change;
        int colorFrom = orgColor[idx];
        int prettyFrom = orgPretty[idx];
        
        // change color -> move prettyFrom from colorFrom to colorTo
        if (op == 1) {
            int colorTo = change;
            colors[colorFrom].erase(colors[colorFrom].find(prettyFrom));
            colors[colorTo].insert(prettyFrom);
            orgColor[idx] = colorTo;
        } 
        // change pretty -> change prettyFrom in colorFrom to prettyTo
        else if (op == 2) {
            int prettyTo = change;
            colors[colorFrom].erase(colors[colorFrom].find(prettyFrom));
            colors[colorFrom].insert(prettyTo);
            orgPretty[idx] = prettyTo;
        }

        getPrettiest();
        q--;
    }
    return 0;
}