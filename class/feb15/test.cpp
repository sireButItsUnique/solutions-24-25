#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // Apply modulo M to each element and sort the array
        for (int i = 0; i < N; ++i) {
            A[i] %= M;
        }
        
        sort(A.begin(), A.end());

        // Duplicate elements and add M to each duplicated element
        vector<int> extendedA = A;
        for (int i = 0; i < N; ++i) {
            extendedA.push_back(A[i] + M);
        }
        
        // Calculate cumulative sums
        vector<long long> cum(extendedA.size() + 1, 0);
        for (int i = 0; i < extendedA.size(); ++i) {
            cum[i + 1] = cum[i] + extendedA[i];
        }
        
        // Find the minimum answer
        long long ans = LLONG_MAX;
        for (int i = 0; i < N; ++i) {
            long long currentAns = cum[i + N] - cum[i + N - N / 2] - cum[i + N / 2] + cum[i];
            ans = min(ans, currentAns);
        }
        
        cout << ans << endl;
    }

    return 0;
}
