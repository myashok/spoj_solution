#include <bits/stdc++.h>
using namespace std;
map<string, bool> prime;
void seive() {
	vector<bool> p((int)1e4+2, true);
	for(int i = 2; i*i < (int)1e4+1; ++i) {
		if(p[i]) {
			for (int j = i * i; j < (int)1e4+1; j += i) {
				p[j] = false;
			}
		}
	}
	for(int i = 2; i < (int)1e4+1; ++i) {
		if(p[i]) {
			prime[to_string(i)] = true;
		//	cout << i <<  " ";
		}
	}
}
void bfs(string start, string goal) {
	map<string, bool> visited;
	map<string, int> dist;
	queue<string> Q;
	visited[start] = true;
	dist[start] = 0;
	Q.push(start);
	string temp, v;
	while(!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		if(u == goal) {
			cout << dist[u] << endl;
			return;
		}
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j <= 9; ++j) {
				temp = u;
				temp[i] = '0' + j;
				if(!visited[temp] and prime[temp] and temp[0] != '0') {
					dist[temp] = dist[u] + 1;
					visited[temp] = true;
					Q.push(temp);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	seive();
	int t;
	cin >> t;
	string a, b;
	while(t--) {
		cin >> a >> b;
		bfs(a, b);
	}
	return 0;
}