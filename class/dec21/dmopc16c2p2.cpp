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

class Dsu {
public:
	vi parent;

	Dsu(int n) {
		n += 2;
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int get(int node) {
        cout << endl;
		if (parent[node] != node) {
			parent[node] = get(parent[node]);
		}
		return parent[node];
	}

	void join(int node1, int node2) {
		int group = get(node1);
		parent[group] = get(node2);
	}
};

int n, m, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    Dsu dsu(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> k;
        int leader, person;
        cin >> leader;
        for (int j = 1; j < k; j++) {
            cin >> person;
            dsu.join(person, leader);
        }
    }

    vi res;
    int infected = dsu.get(1);
    for (int i = 1; i <= n; i++) {
        if (dsu.get(i) == infected) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}