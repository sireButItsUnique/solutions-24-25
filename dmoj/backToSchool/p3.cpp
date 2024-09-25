#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll MOD = 1e9 + 7;

class Segtree {
public:
    vector<ll> tree;
    vector<ll> underwhelming;
    Segtree(ll n) {
        ll s = 1;
        while (s < n) {
            s *= 2;
        }
        this->tree = vector<ll>(2 * s, 0);
        this->underwhelming = vector<ll>(2 * s, 0);
    }    
    
    void print() {
        cout << "tree is [";
        for (ll i = 1; i < this->tree.size() - 1; i++) {
            cout << this->tree[i] << ", ";
        }
        cout << this->tree[this->tree.size() - 1] << "]\n";
        return;
    }
    
    void update(ll pos, ll val) {
        ll at = pos + (this->tree.size() / 2);
        this->tree[at] = val;
        this->recUpdate(at / 2);
        return;
    }
    
    ll get() {
        return this->tree[1];
    }

private:
    void recUpdate(ll pos) {
        this->tree[pos] = max(this->tree[pos * 2], this->tree[pos * 2 + 1]);
        this->underwhelming[pos] = this->underwhelming[pos * 2] + this->underwhelming[pos * 2 + 1];
        this->underwhelming[pos] += pow((ll)abs(this->tree[pos * 2] - this->tree[pos * 2 + 1]), 2);

        if (pos == 0) {
            return;
        }
        this->recUpdate(pos / 2);
        return;
    }
};

ll n, tmp;
vector<ll> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll sum = (1 + n) * (n / 2);
    a = vector<ll>(n);

    Segtree* seg = new Segtree(n);
    for (ll i = 1; i < n; i++) {
        cin >> a[i];
        sum -= a[i];
        seg->update(i, a[i]);
    }
    seg->update(0, sum);
    //seg->print();
    cout << seg->underwhelming[1] << " ";

    for (ll i = 1; i < n; i++) {
        seg->update(i, sum);
        seg->update(i-1, a[i]);
        cout << seg->underwhelming[1] << " ";
        //seg->print();
    }
    cout << endl;

    return 0;
}

/*
4
2 4
1 2 4 3

4
2 4
2 1 4 3

4
4 3
2 4 1 3

4
4 3
2 4 3 1
*/