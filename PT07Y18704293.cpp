#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g((int)2e5+1);
map<int, bool> visited;
void dfs(int i) {
	visited[i] = true;
	for(auto it = g[i].begin(); it != g[i].end(); ++it)
		if(!visited[*it]) dfs(*it);
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int u, v;
	if(m != n-1) {
		cout << "NO\n";
		return 0;
	}
	while(m--) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		if(!visited[i]) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}