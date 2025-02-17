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

int t, n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vi a(n);
        vector<vi> rule(k, vi(3)); // r, l, tree

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> rule[i][1] >> rule[i][0] >> rule[i][2];
        }
        sort(a.begin(), a.end());
        sort(rule.begin(), rule.end());

        vi empty;
        int ruleIdx = 0;
        for (int i = 0; i < n; i++) {
            
            while (ruleIdx < k && rule[ruleIdx][0] < a[i]) {
                int have = upper_bound(a.begin(), a.end(), rule[ruleIdx][0]) - lower_bound(a.begin(), a.end(), rule[ruleIdx][1]);
                have -= upper_bound(empty.begin(), empty.end(), rule[ruleIdx][0]) - lower_bound(empty.begin(), empty.end(), rule[ruleIdx][1]);
                int need = rule[ruleIdx][2] - have;
                
                while (need > 0) {
                    empty.pop_back();
                    need--;
                }
                ruleIdx++;
            }

            empty.push_back(a[i]);
        }

        while (ruleIdx < k) {
            int have = upper_bound(a.begin(), a.end(), rule[ruleIdx][0]) - lower_bound(a.begin(), a.end(), rule[ruleIdx][1]);
            have -= upper_bound(empty.begin(), empty.end(), rule[ruleIdx][0]) - lower_bound(empty.begin(), empty.end(), rule[ruleIdx][1]);
            int need = rule[ruleIdx][2] - have;
            
            while (need > 0) {
                empty.pop_back();
                need--;
            }
            ruleIdx++;
        }
        cout << empty.size() << '\n';
    }
    

    return 0;
}