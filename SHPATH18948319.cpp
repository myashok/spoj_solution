#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > g;
map<string, int> mymap;
int n;
void clearAndResize(int n) {
	g.clear();
	mymap.clear();
	int s = n+1;
	g.resize(s);
}
int dijikstra(int s, int go) {
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > Q;
	vector<int> dis(n+1, INT_MAX);
	dis[s] = 0;
	Q.push({0, s});
  // cout << g[1].begin()->first << endl;
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();
		if(u.second == go) {
			return dis[go];
		}
	//	cout << u.second << endl;
		int in = u.second;
		for (auto i = g[in].begin(); i != g[in].end(); ++i) {
			int v = i->second;
			int wt = i->first;
			if(u.first + wt < dis[v]) {
				dis[v] = u.first + wt;
				Q.push({dis[v], v});
			}
		}
	}
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t; cin >> t;
	string s;
	int u , c;
	while(t--) {
		cin >> n;
		clearAndResize(n);
		for (int i = 0; i < n; ++i) {
			cin >> s;
			mymap[s] = i+1;
			int j; cin >> j;
			for (int k = 0; k < j; ++k) {
				cin >> u >> c;
				g[i+1].push_back({c, u});
			//	cout << g[i+1].begin()->first << endl;
			}
		}
		int r; cin >> r;
		string s1, s2;
		for (int i = 0; i < r; ++i) {
			cin >> s1 >> s2;
			cout << dijikstra(mymap[s1], mymap[s2]) << endl;
		}
	}
	return 0;
}