#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
void bfs(int a, int b, int c) {
	queue<pair<int, int> > Q;
	map<pair<int, int>, int > dis;
	map<pair<int, int>, bool> visited;
	Q.push(mp(0,0));
	dis[mp(0,0)] = 0;
	visited[mp(0,0)] = true;
	while(!Q.empty()) {
		auto u = Q.front(); Q.pop();
		int x = u.first;
		int y = u.second;
		if(x == c || y == c) {
			cout << dis[mp(x, y)] << endl;
			return ;
		}
		for (int i = 1; i <= 3; ++i) {
			switch(i) {
				case 1: 
					if(x < a && !visited[mp(a, y)]) {
						Q.push(mp(a, y));
						dis[mp(a, y)] = dis[mp(x, y)] + 1;
						visited[mp(a, y)] = true;
					}
					if(y < b && !visited[mp(x, b)]) {
						Q.push(mp(x, b));
						dis[mp(x, b)] = dis[mp(x, y)] + 1;
						visited[mp(x, b)] = true;
					}
					break;
				case 2: //emptying the vessel
					if(x > 0 && !visited[mp(0, y)]) {
						Q.push(mp(0, y));
						dis[mp(0, y)] = dis[mp(x, y)] + 1;
						visited[mp(0, y)] = true;
					}
					if(y > 0 && !visited[mp(x, 0)]) {
						Q.push(mp(x, 0));
						dis[mp(x, 0)] = dis[mp(x, y)] + 1;
						visited[mp(x, 0)] = true;
					}
					break;
				case 3:
					int tb = min(a-x, y);
					if(x < a && !visited[mp(x + tb, y - tb)]) {
						Q.push(mp(x + tb, y - tb));
						dis[mp(x + tb, y - tb)] = dis[mp(x, y)] + 1;
						visited[mp(x + tb, y - tb)] = true;
					}
					int ta = min(x, b - y);
					if(y < b && !visited[mp(x - ta, y + ta)]) {
						Q.push(mp(x - ta, y + ta));
						dis[mp(x - ta, y + ta)] = dis[mp(x, y)] + 1;
						visited[mp(x - ta, y + ta)] = true;
					}
					break;
			}
		}
	}
	cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int a, b, c;
	while(t--) {
		cin >> a >> b >> c;
		if (c > max(a,b))
			cout << "-1\n";
		else {
			bfs(a, b, c);
		}
	}
	return 0;
}