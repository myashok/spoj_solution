#include <bits/stdc++.h>
using namespace std;
#define pb push_back
/*
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!*/
const int W = 0, B = 1; 
int n;
vector<int> color;
bool bfs(vector<vector<int> > &g, int i) {
	queue<int> Q;
	Q.push(i);
	color[i] = 0;
	bool flag = true;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (auto it = g[u].begin(); it != g[u].end(); ++it) {
			int v = *it;
			if(color[v] == -1) {
				color[v] = color[u]^1;
				Q.push(v);
			}
			else if(color[v] == color[u]) flag = false;
		}
	}
	return flag;
}
bool check(vector<vector<int> > &g) {
	color.clear();
	color.resize(n+1, -1);
	for (int i = 1; i <= n; ++i) {
		if(color[i] == -1) {
			if(!bfs(g, i)) return false;
		}
	}
	return true;
}
int main() {
	// your code goes here
	int t; cin >> t;
	vector<vector<int> > g;
	int  e, u , v;
	for (int i = 0; i < t; ++i) {
		cin >> n >> e;
		g.resize(n+1);
		printf("Scenario #%d:\n", i+1);
		for (int i = 0; i < e; ++i) {
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(check(g)) {
			printf("No suspicious bugs found!\n");
		}
		else {
			printf("Suspicious bugs found!\n");
		}
		g.clear();
	}
	return 0;
}