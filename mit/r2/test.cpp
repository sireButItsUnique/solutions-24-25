#include <bits/stdc++.h>
using namespace std;

struct op {
    int type, x, y; // 1 -> swap, 2 -> move
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<op> ans; // Store the operations
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i] || a[i] == i + 1) continue; // Already in place

        // Find the cycle
        vector<int> cycle;
        int current = i;
        while (!visited[current]) {
            visited[current] = true;
            cycle.push_back(current);
            current = a[current] - 1; // Go to the next element in the cycle
        }

        // Resolve the cycle using swaps
        for (int j = 1; j < (int)cycle.size(); j++) {
            ans.push_back({1, cycle[0] + 1, cycle[j] + 1}); // Swap elements
            swap(a[cycle[0]], a[cycle[j]]);
        }
    }

    // Output the results
    cout << ans.size() << '\n';
    for (auto &op : ans) {
        cout << op.type << ' ' << op.x << ' ' << op.y << '\n';
    }
}

/*
0 1 2 3 4
*/