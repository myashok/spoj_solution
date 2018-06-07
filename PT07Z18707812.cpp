#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector<vector<int> > g((int)1e4+1);
map<int, bool> visited;
int n;
int d = 0, curr, mx = 0, ans = 0;
void dfs(int i) {
	visited[i] = true;
	for (auto it = g[i].begin(); it != g[i].end(); ++it) {
		if(!visited[*it]) {
			d = d + 1;
			curr = *it;
			dfs(*it);
		}
	}
	if (d > mx) {
		mx = d;
		ans = curr;
	}
	d--; 
}
void longestpath() {
	 d = 0;
	 curr = 1;
	 dfs(1);
	 //cout << ans << endl;
	 curr = ans; 
	 d = mx = ans = 0;
	 visited.clear();
	 dfs(curr);
	 cout << mx << endl;
}
int main() {
	// your code goes here
	int t, u, v;
	cin >> t;
	n = t;
	while(t--) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	longestpath();
	return 0;
}