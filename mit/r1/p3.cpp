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

int t;
int n, k;
vi a, lds;

int calc() {
    reverse(a.begin(), a.end());
    lds = vi();

    for (int num : a) {
        // Find the position where num can replace an element in lds
        auto it = lower_bound(lds.begin(), lds.end(), num);
        
        if (it == lds.end()) {
            // If num is larger than all elements, append it
            lds.push_back(num);
        } else {
            // Otherwise, replace the element at the found position
            *it = num;
        }
    }
    
    // The size of lds is the length of the Longest Decreasing Subsequence
    return lds.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) { 
        cin >> n >> k;
        a = vi(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        calc();
        
    }

    return 0;
}