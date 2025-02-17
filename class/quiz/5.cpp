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

int main() {
    int n;
    cin >> n;

    vector<int> next(n);
    for (int i = 0; i < n; ++i) {
        cin >> next[i];
    }

    vector<int> visited(n + 1, -1);  // -1 means not processed
    vector<int> result(n + 1, 0);    // Stores the number of unique houses visited

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == -1) {  // If this house is unprocessed
            vector<int> path;
            int node = i;

            // Traverse until we reach a fully processed node or a cycle
            while (visited[node] == -1) {
                visited[node] = 0;  // Mark as currently visiting
                path.push_back(node);
                node = next[node - 1];
            }

            int path_length = 0;

            if (visited[node] == 1) {
                // If the node is already fully processed, reuse its result
                path_length = result[node];
            } else {
                // Found a cycle
                int cycle_start = 0;
                while (path[cycle_start] != node) {
                    ++cycle_start;
                }
                path_length = path.size() - cycle_start;

                // Mark all nodes in the cycle
                for (int j = cycle_start; j < path.size(); ++j) {
                    result[path[j]] = path_length;
                }
            }

            // Process nodes before the cycle
            for (int j = path.size() - 1; j >= 0; --j) {
                if (result[path[j]] == 0) {
                    ++path_length;
                    result[path[j]] = path_length;
                }
                visited[path[j]] = 1;  // Mark as fully processed
            }
        }
    }

    // Output the results for each house
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}
