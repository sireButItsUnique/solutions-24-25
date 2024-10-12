#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

ll n;
string s;
double low = INT_MAX;
int L, R;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int colors = 1; colors <= 26; colors++) {

        // slide window, longest subarray w/ colors
       
        int ptr1 = 0, distinct = 0;
        vi cnt(26, 0);
        for (int ptr2 = 0; ptr2 < n; ptr2++) {
            
            if (!cnt[s[ptr2] - 'a']) distinct++;
            cnt[s[ptr2] - 'a']++;
            while (distinct > colors) {
                if (cnt[s[ptr1] - 'a'] == 1) distinct--;
                cnt[s[ptr1] - 'a']--;
                ptr1++;
            }

            double score = (double)distinct / (ptr2 - ptr1 + 1); 
            if (score <= low) {
                R = ptr1 + 1;
                L = ptr2 + 1;
                low = score;
            }
        }
    }
    cout << R << " " << L << endl;
    return 0;
}