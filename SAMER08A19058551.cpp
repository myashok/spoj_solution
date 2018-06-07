#include <bits/stdc++.h>
#define si(x) scanf("%d", &x)
#define mp make_pair
using namespace std;
vector<vector<pair<int, int> > > g, rg; // cost, dest
int n, e;
int src, dest;
map<pair<int, int>, bool> absent;
void dijikstra(int src, vector<int> &dis, vector<vector<pair<int, int> > > &g) {
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > Q;
	Q.push({0, src});
	dis[src] = 0;
	while(!Q.empty()) {
		// while(Q.top().first != dis[Q.top().second]) {
		// 	Q.pop();
		// }
		auto x = Q.top(); Q.pop();
		int u = x.second;
		for (auto it = g[u].begin(); it != g[u].end(); ++it) {
			int wt = it->first;
			int v = it->second;
			if(!absent[mp(u, v)] && dis[u] + wt < dis[v]) {
				dis[v] = dis[u] + wt;
				Q.push({dis[v], v});
			} 
		}
	}
}
inline bool markabsent(vector<int> &disu, vector<int> &disv) {
	int d = disu[dest];
	int v, wt;
//	cout << d << endl;
	for (int i = 0; i < n; ++i) {
		for (auto it = g[i].begin(); it != g[i].end(); ++it) {
			v = it->second;
			wt = it->first;
			if((disu[i] + wt + disv[v]) == d) {
				absent[mp(i, v)] = true;
		//		cout << i << " " << v << endl;
			}
		}
	}
//	cout << endl;
}
void solve() {
	vector<int> disu(n, INT_MAX), disv(n, INT_MAX);
	//two dijikstra
	absent.clear();
	dijikstra(src, disu, g);
	dijikstra(dest, disv, rg);
	markabsent(disu, disv);
	disu.assign(n, INT_MAX);
 	dijikstra(src, disu, g);
 	if(disu[dest] == INT_MAX) printf("-1\n");
	 else printf("%d\n", disu[dest]);
}
int main() {
	ios::sync_with_stdio(false);
	int u, v, c;
	while(1) {
		si(n);si(e);	
		if (n == 0 && e == 0) break;
		si(src);si(dest);
		g.clear(); g.resize(n);
		rg.clear(); rg.resize(n);
		for (int i = 0; i < e; ++i) {
			si(u);si(v);si(c);
			g[u].push_back({c, v});
			rg[v].push_back({c, u});
		}
		solve();
	}
	return 0;
}