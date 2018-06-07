#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
vector<vector<bool> > visited;
vector<vector<int> > len;
vector<vector<char> > g;
int m, n;
queue<pair<int, int> > Q;
int x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
void init() {
	visited.clear();
	len.clear();
	g.clear();
	visited.resize(m, vector<bool>(n, false));
	len.resize(m, vector<int>(n, 0));
	g.resize(m, vector<char>(n));
}
inline bool issafe(int x, int y) {
	return x >= 0 and x < m and y >= 0 and y < n;
}
void BFS() {
	while(!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		for(int i = 0; i < 8; ++i) {
			int nx = u.fi + x[i];
			int ny = u.se + y[i];
			if(issafe(nx, ny)){
				if(!visited[nx][ny] && g[u.fi][u.se] == (g[nx][ny]-1)) {
					visited[nx][ny] = true;
					Q.push({nx, ny});
					len[nx][ny] = len[u.fi][u.se] + 1;
				}
				else if(g[u.fi][u.se] == (g[nx][ny]-1))
					len[nx][ny] = max(len[nx][ny], (len[u.fi][u.se]+1));
			}
		}
	}
	int mx = -1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if(mx < len[i][j]) {
				mx = len[i][j];
			}
		}
	}
	cout << mx << endl;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	//int m, n;
	int co = 1;
	while(1) {
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		init();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
				if(g[i][j] == 'A') {
					visited[i][j] = true;
					len[i][j] = true;
					Q.push({i,j});
				}
			}
		}
		cout << "Case " << co << ": ";
		BFS();
		co++;
	}
	return 0;
}