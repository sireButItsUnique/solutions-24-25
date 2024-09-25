#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
ll MOD = 1e9 + 7;

// split in middle -> one w/ more characters should be the extra, if not try other split
string u;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> u;
    if (u.size() % 2 == 0) {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }

    ll split = u.size() / 2;

    // ptr1 0 1 | 2 3 4 ptr2
    int ptr2 = 0;
    bool foundDiscreptancy = false;
    bool firstHalf = true;
    for (int ptr1 = 0; ptr1 < split; ptr1++) {
        // cout << u[ptr1] << " vs " << u[split + ptr2 + foundDiscreptancy] << endl;
        if (u[ptr1] != u[split + ptr2 + foundDiscreptancy]) {
            if (foundDiscreptancy) {
                firstHalf = false;
                break;
            } else {
                if (u[ptr1] != u[split + ptr2 + 1]) {
                    firstHalf = false;
                    break;
                }
                foundDiscreptancy = true;
            }
        }
        ptr2++;
    }
    if (foundDiscreptancy && u.back() != u[split - 1]) {
        firstHalf = false;
    }

    // ptr1 0 1 2 | 3 4 ptr2
    ptr2 = 0;
    foundDiscreptancy = false;
    bool secondHalf = true;
    for (int ptr1 = 0; ptr1 < split; ptr1++) {
        // cout << u[ptr1 + foundDiscreptancy] << " vs " << u[split + ptr2 + 1] << endl;
        if (u[ptr1 + foundDiscreptancy] != u[split + ptr2 + 1]) {
            if (foundDiscreptancy) {
                secondHalf = false;
                break;
            } else {
                if (u[ptr1 + 1] != u[split + ptr2 + 1]) {
                    secondHalf = false;
                    break;
                }
                foundDiscreptancy = true;
            }
        }
        ptr2++;
    }
    if (foundDiscreptancy && u.back() != u[split]) {
        secondHalf = false;
    }

    // output res
    if (firstHalf && secondHalf) {
        if (u.substr(0, split) == u.substr(split + 1, split)) {
            cout << u.substr(split + 1, split) << endl;
            return 0;
        }
        cout << "NOT UNIQUE" << endl;
        return 0;
    }
    if (firstHalf) { // first half is ans
        cout << u.substr(0, split) << endl;
        return 0;
    }
    if (secondHalf) { // second half is ans
        cout << u.substr(split + 1, split) << endl;
        return 0;
    }

    cout << "NOT POSSIBLE" << endl;
    return 0;
}