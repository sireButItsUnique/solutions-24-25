#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

ll n, m;
vector<ll> a, b, res;

vector<ll> initializeDiffArray(vector<ll>& A) 
{ 
    int n = A.size(); 
  
    // We use one extra space because 
    // update(l, r, x) updates D[r+1] 
    vector<ll> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  
// Does range update 
void update(vector<ll>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 
  
// Prints updated Array 
void printArray(vector<ll>& A, vector<ll>& D) 
{ 
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
  
        // Note that A[0] or D[0] decides 
        // values of rest of the elements. 
        else
            A[i] = D[i] + A[i - 1]; 
  
        cout << A[i] << " "; 
    } 
    cout << endl; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a = vector<ll>(n);
    b = vector<ll>(n);
    res = vector<ll>(m, 0);
    vector<ll> D = initializeDiffArray(res); 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int studentIdx = 0;
    for (int i = 0; i < n; i++) {
        update(D, studentIdx, min(studentIdx + b[i], m) - 1, a[i]);
        studentIdx += b[i];
        if (studentIdx >= m) {
            studentIdx -= m;
            if (studentIdx - 1 >= 0) {
                update(D, 0, studentIdx - 1, a[i]);
            }
        }
    }

    printArray(res, D);
    return 0;
}