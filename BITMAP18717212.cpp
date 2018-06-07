#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
string s[200];
vector<vector<int> > dis(200, vector<int>(200, 400)); 
int n, m;
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
vector<vector<bool> > visited(200, vector<bool>(200, false));
queue<pair<int, int> > Q; 
void bfs() {
	 while(!Q.empty()) {
	 	auto u = Q.front();
	 	Q.pop();
	 	int r = u.first;
	 	int c = u.second;
	 	for (int i = 0; i < 4; ++i) {
	 		int newr = r + x[i];
	 		int newc = c + y[i];
	 		if(!safe(newr, newc)) continue;
	 		if(!visited[newr][newc]) {
	 			Q.push(mp(newr, newc));
	 			visited[newr][newc] = true;
	 		}
	 		if(dis[newr][newc] > dis[r][c] + 1)
	 			dis[newr][newc] = dis[r][c] + 1;
	 	}
	 }
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		visited.assign(200, vector<bool>(200, false));
	    dis.assign(200, vector<int>(200, 400)); 
		for(int i = 0; i < n; ++i) 
			cin >> s[i];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == '1') {
					Q.push(mp(i,j));
					dis[i][j] = 0;
					visited[i][j] = true;
				}
			}
		}
		bfs();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << dis[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}