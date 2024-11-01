#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX_ARR_LEN = 1e5 + 5;

// Function to update the BIT at a given index
void updateBIT(vector<ll>& BIT, int idx, ll val) {
    while (idx < MAX_ARR_LEN) {
        BIT[idx] += val;
        idx += (idx & -idx);  // Move to the next index
    }
}

// Function to get the prefix sum from the BIT up to a given index
ll queryBIT(const vector<ll>& BIT, int idx) {
    ll res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (idx & -idx);  // Move to the parent index
    }
    return res;
}

// Function to count elements <= x using the BIT
ll countLessOrEqual(const vector<ll>& BIT, int x) {
    return queryBIT(BIT, x);
}

int main() {
    // Example usage:
    vector<ll> BIT(MAX_ARR_LEN, 0);
    vector<ll> arr = {1, 5, 2, 6, 3, 7, 4, 4};  // Example array

    // Building the BIT with initial values
    for (int val : arr) {
        updateBIT(BIT, val, 1);  // Increment the count of each value in the BIT
    }

    // Query how many elements are <= 4
    while (true) {
        int x;
        cin >> x;
        cout << "Number of elements <= " << x << " is: " << countLessOrEqual(BIT, x) << endl;
    }
    

    return 0;
}
