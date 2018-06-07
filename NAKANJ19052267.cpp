#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
#define pr(x) printf("%d\n", x);
using namespace std;
int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y[] = {2, -2, -2, 2, 1, -1, 1, -1};
pair<int, int> src, goal;
bool valid(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}
void bfs() {
	map<pair<int, int>, bool> visited;
	map<pair<int, int>, int> dis;
	queue<pair<int, int> > Q;
	Q.push(src);
	dis[src] = 0;
	visited[src] = true;
	int ux, uy;
	while(!Q.empty()) {
		auto u = Q.front(); Q.pop();
		for (int i = 0; i < 8; ++i) {
			ux = u.first + x[i];
			uy = u.second + y[i];
			if(valid(ux, uy) && !visited[{ux, uy}]) {
				Q.push({ux, uy});
				dis[{ux, uy}] = dis[u] + 1;
				visited[{ux, uy}] = true;
			}
		}
	}
	cout << dis[goal] << endl;
}
int main() {
	int t;
	si(t);
	string a, b;
	while(t--) {
		cin >> a >> b;
	//	cout << a << b << endl;
		src.first = (int)(a[0]-'a');
		src.second = (int)(a[1]-'1');
		goal.first = (int)(b[0]-'a');
		goal.second = (int)(b[1]-'1');
	//	cout << src.first << " " << src.second << endl;
	//	cout << goal.first << " " << goal.second << endl;
		bfs();
	}
	return 0;
}