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
	vl parent;
    vl score;
    vi size;

	Dsu(int n) {
		parent.resize(n + 1);
        score.resize(n + 1, 0);
        size.resize(n + 1, 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}

    void setScore(int node, ll s) {
        score[node] = s;
    }

    ll getScore(int node) {
        int group = getGroup(node);
		return score[group];
    }

    int getSize(int node) {
        int group = getGroup(node);
		return size[group];
    }

	int getGroup(int node) {
		if (parent[node] != node) {
			parent[node] = getGroup(parent[node]);
		}
		return parent[node];
	}

	void join(int node1, int node2) {
		int group1 = getGroup(node1);
        int group2 = getGroup(node2);
        if (group1 == group2) return;

        if (size[group1] < size[group2]) {
            parent[group1] = group2;
            size[group2] += size[group1];
            score[group2] += score[group1];
        } else {
            parent[group2] = group1;
            size[group1] += size[group2];
            score[group1] += score[group2];
        }
	}
};

ll n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    Dsu dsu(n);
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        dsu.setScore(i, a);
    }
    
    while (q--) {
        int op, a, b;
        cin >> op >> a;
        if (op == 1) {
            cin >> b;
            dsu.join(a, b);
        } else if (op == 2) {
            cout << dsu.getSize(a) << "\n";
        } else if (op == 3) {
            cout << dsu.getScore(a) << "\n";
        }
    }

    return 0;
}