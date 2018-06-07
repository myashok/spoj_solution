#include <bits/stdc++.h>
using namespace std;
int dp[(int)1e5+1][2];
vector<int> g[(int)1e5+1];
int dfs(int u, int p) {
	 dp[u][1] = 1;
	 for (int i = 0; i < g[u].size(); ++i) {
	 	int v = g[u][i];
	 	if (v == p) continue;
	 	dfs(v, u);
	 	dp[u][1] += min(dp[v][1], dp[v][0]);
	 	dp[u][0] += dp[v][1];
	 }
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int u, v;
	for (int i = 0; i+1 < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	int ans = min(dp[1][1], dp[1][0]);
	cout << max(ans, 1) << endl;
	return 0;
}