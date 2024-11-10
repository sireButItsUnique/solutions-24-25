#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>  
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define bitcnt __builtin_popcount
ll MOD = 1e9 + 7;
ll BASE = 31;

// never makes sense to hop on train again -> need to tunnel the entire way to end
// check each tunnel's dist to end point -> bfs
vi dist(2e5 + 5, 1e9), stations(2e5 + 5);
multiset<pll> res;
vector<vi> adj(2e5 + 5);
ll n, w, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> d;
    for (int a, b, i = 0; i < w; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    // bfs to find fastest route to exit
    queue<pii> q;
    dist[n] = 0;
    q.push({n, 0});
    while (q.size()) {
        pii cur = q.front();
        q.pop();
        for (int neighbour: adj[cur.first]) {
            if (dist[neighbour] > cur.second + 1) {
                q.push({neighbour, cur.second + 1}); 
                dist[neighbour] = cur.second + 1;
            }
        }
    }

    // get stations
    for (int station, i = 0; i < n; i++) {
        cin >> station;
        stations[i + 1] = station;
        res.insert({i + dist[station], station});
        //cout << "station " << station << " at dist " << (i + dist[station]) << endl;
    }

    // start days
    for (int x, y, i = 0; i < d; i++) {
        cin >> x >> y;
        ll newX = y + dist[stations[x]] - 1;
        ll newY = x + dist[stations[y]] - 1;
        res.erase(res.find({x + dist[stations[x]] - 1, stations[x]}));
        res.erase(res.find({y + dist[stations[y]] - 1, stations[y]}));
        res.insert({newX, stations[x]});
        res.insert({newY, stations[y]});
        swap(stations[x], stations[y]);
        cout << (*(res.begin())).first << '\n';
    }
    return 0;
}