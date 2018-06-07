#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > g, rg; // cost node;
int n, e;
void clearAndResize() {
	g.clear();
	rg.clear();
	g.resize(n+1);
	rg.resize(n+1);
}
long long dijikstra(vector<vector<pair<int, int> > > &g) {
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	vector<int> d(n+1, INT_MAX);
	Q.push({0, 1});
	d[1] = 0;
	while(!Q.empty()) {
		auto u = Q.top().second; Q.pop();
	//	cout << u << endl;
		for (auto it = g[u].begin(); it != g[u].end(); ++it) {
			int v = it->second;
			int wt = it->first;
			if(d[u] + wt < d[v]) {
				d[v] = d[u] + wt;
				Q.push({d[v], v});
			}
		}
	}
	long long temp = 0;
	for (int i = 2; i <= n; ++i)
		temp += d[i];
	return temp;
} 
void solve() {
	long long  ans = 0;
	ans += (long long)dijikstra(g);
	ans += (long long)dijikstra(rg);
	cout << ans << endl;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int u, v, c;
	while(t--) {
		cin >> n >> e;
		clearAndResize();
		for (int i = 0; i < e; ++i) {
			cin >> u >> v >> c;
			g[u].push_back({c, v});
			rg[v].push_back({c, u});
		}
		solve();
	}
	return 0;
}