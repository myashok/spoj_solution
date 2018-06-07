#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<ll, ll > > > g; // cost node;
ll  n, e;
ll  src, dest;
void clearAndResize() {
	g.clear();
	g.resize(n+1);
}
ll dijikstra() {
	priority_queue< pair<ll, ll >, vector<pair<ll, ll > >, greater<pair<ll, ll > > > Q;
	vector<ll> d(n+1, LLONG_MAX);
	Q.push({0, src});
	d[src] = 0;
	while(!Q.empty()) {
		auto u = Q.top().second; Q.pop();
		for (auto it = g[u].begin(); it != g[u].end(); ++it) {
			ll  v = it->second;
			ll wt = it->first;
			if(d[u] + wt < d[v]) {
				d[v] = d[u] + wt;
				Q.push({d[v], v});
			}
		}
	}
	// for (int i = 1; i <= n; ++i) 
	// cout << i << " "<< d[i] << endl;
	// cout << endl;
	//cout << d[dest] << " " << src << " " << dest << endl;
	if(d[dest] != LLONG_MAX) return d[dest];
	else return -1;
} 
void solve() {
	ll   ans = 0;
	if ((ans = dijikstra()) != -1) cout << ans << endl;
	else cout << "NONE\n";
}
int  main() {
	// your code goes here
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll  t;
	cin >> t;
	ll  u, v;
	ll c;
	while(t--) {
		cin >> n >> e >> src >> dest;
		clearAndResize();
		for (ll  i = 0; i < e; ++i) {
			cin >> u >> v >> c;
			g[u].push_back({c, v});
			g[v].push_back({c, u});
		}
		solve();
	}
	return 0;
}