#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int , int > > > g; // cost node;
int  n, e;
int  src, dest;
void clearAndResize() {
	g.clear();
	g.resize(n+1);
}
int dijikstra() {
	priority_queue< pair<int , int >, vector<pair<int , int > >, greater<pair<int , int > > > Q;
	vector<int > d(n+1, INT_MAX);
	Q.push({0, src});
	d[src] = 0;
	while(!Q.empty()) {
		auto u = Q.top().second; Q.pop();
		for (auto it = g[u].begin(); it != g[u].end(); ++it) {
			int  v = it->second;
			int wt = it->first;
			if(d[u] + wt < d[v]) {
				d[v] = d[u] + wt;
				Q.push({d[v], v});
			}
		}
	}
	if(d[dest] != INT_MAX) return d[dest];
	else return -1;
} 
void solve() {
	int   ans = 0;
	if ((ans = dijikstra()) != -1) cout << ans << endl;
	else cout << "NONE\n";
}
int  main() {
	// your code goes here
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int  t;
	cin >> t;
	int  u, v;
	int c;
	while(t--) {
		cin >> n >> e >> src >> dest;
		clearAndResize();
		for (int  i = 0; i < e; ++i) {
			cin >> u >> v >> c;
			g[u].push_back({c, v});
			g[v].push_back({c, u});
		}
		solve();
	}
	return 0;
}