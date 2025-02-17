#include <bits/stdc++.h>
using namespace std;

struct op {
	int id, x, y;
};

int n;
vector<int> a;
vector<op> ans; // {1, x, y} to denote swap x and y


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) mp[a[i]] = i;
	for (int i = 0; i < n; i++) {
		if (a[i] != i+1) {
			ans.push_back({1, i, mp[i+1]});
			swap(a[i], a[mp[i+1]]);
			mp[a[mp[i+1]]] = mp[i+1];
			mp[a[i]] = i;
		}
	}
	cout << ans.size() << '\n';
	for (auto &x : ans) {
		cout << x.id << ' ' << x.x+1 << ' ' << x.y+1 << '\n';
	}
}