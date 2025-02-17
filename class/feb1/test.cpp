#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, k;
vector<int> a;
vector<pair<int, int>> clumps;
vector<vector<int>> dp;

// Preprocess consecutive marbles into clumps of (color, frequency)
void preprocess() {
    for (int i = 0; i < n; i++) {
        if (!clumps.empty() && clumps.back().first == a[i]) {
            clumps.back().second++;
        } else {
            clumps.emplace_back(a[i], 1);
        }
    }
}

// DP function to solve the problem optimally
int solve(int l, int r) {
    if (l > r) return 0;  // Base case: empty range
    if (dp[l][r] != -1) return dp[l][r];

    int color = clumps[l].first;
    int count = clumps[l].second;

    int minInsertions = INF;

    // Case 1: If this clump has at least K marbles, remove it immediately
    if (count >= k) {
        minInsertions = solve(l + 1, r);
    }

    // Case 2: Try merging with later occurrences of the same color
    for (int j = l + 1; j <= r; j++) {
        if (clumps[j].first == color) {
            int needed = k - (count + clumps[j].second);
            if (needed <= 0) { // Can be removed without extra insertions
                minInsertions = min(minInsertions, solve(l + 1, j - 1) + solve(j + 1, r));
            } else { // Requires insertions to merge
                minInsertions = min(minInsertions, solve(l + 1, j - 1) + solve(j + 1, r) + needed);
            }
        }
    }

    // Case 3: Try removing the clump alone by inserting (K - count) marbles
    minInsertions = min(minInsertions, (k - count) + solve(l + 1, r));

    // Case 4: Try splitting the sequence at different points
    for (int mid = l; mid < r; mid++) {
        minInsertions = min(minInsertions, solve(l, mid) + solve(mid + 1, r));
    }

    return dp[l][r] = minInsertions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    preprocess();
    int m = clumps.size();
    dp.assign(m, vector<int>(m, -1));

    cout << solve(0, m - 1) << "\n";

    return 0;
}
