#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector<vector<int> > g((int)1e4+1);
map<int, bool> visited;
int d[(int)1e4+1];
int n;
void bfs(int i) {
	queue<int> Q;
	Q.push(i);
	visited[i] = true;
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (auto it = g[v].begin(); it != g[v].end(); ++it) {
			if(!visited[*it]) {
				Q.push(*it);
				visited[*it] = true;
				d[*it] = d[v] + 1;
			}
		}
	}
}
void longestpath() {
	 d[1] = 0;
	 bfs(1);
	 //for (int i = 1; i <= n; ++i)
	 //	cout << i << " " << d[i] << endl;
	 int u = max_element(d+1, d+n+1) - (d);
	 visited.clear();
	 //cout << u << endl;
	 d[u] = 0;
	 bfs(u);
	 cout << *max_element(d+1, d+n+1) << endl;
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