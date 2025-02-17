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

class Dsu {
public:
	vi parent, size;

	Dsu(int n) {
		n += 2;
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int getGroup(int node) {
		if (parent[node] != node) {
			parent[node] = getGroup(parent[node]);
		}
		return parent[node];
	}

	int getSize(int node) {
        int group = getGroup(node);
		return size[group];
    }

	void join(int node1, int node2) {
		int group1 = getGroup(node1);
        int group2 = getGroup(node2);
        if (group1 == group2) return;

        if (size[group1] < size[group2]) {
            parent[group1] = group2;
            size[group2] += size[group1];
        } else {
            parent[group2] = group1;
            size[group1] += size[group2];
        }
	}
};