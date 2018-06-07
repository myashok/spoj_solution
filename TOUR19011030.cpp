#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g, rg;
int n;
stack<int> S;
int cnt = 0;
vector<bool> visited;
void dfsutil(int i, vector<vector<int> > & g) {
	visited[i] = true;
	cnt++;
	for (auto it = g[i].begin(); it != g[i].end(); ++it) {
		if(!visited[*it])
			dfsutil(*it, g);
	}
	S.push(i);
}
void dfs(vector<vector<int> > & g) {
	visited.clear();
	visited.resize(n+1, false);
 	for (int i = 1; i <= n; ++i) {
 		if(!visited[i])
 			dfsutil(i, g);
 	}
}

int solve() {
	cnt = 0;
	if(!S.empty()) cout << S.top();
	dfs(g);
	cnt = 0;
	visited.clear();
	visited.resize(n+1, false);
//	cout << S.top() << " ";
    dfsutil(S.top(), rg);
    while(!S.empty()) S.pop();
	return cnt;
}
void print(vector<vector<int> > &g) {
	for (int i = 1; i <= n; ++i) {
		cout << i << "-> ";
		for (auto it = g[i].begin(); it != g[i].end(); ++it)
			cout << *it << " ";
		cout << endl;
	} 
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	int no, x;
	while(t--) {
		cin >> n;
		g.clear();
		g.resize(n+1);
		rg.clear();
		rg.resize(n+1);
		int count = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> no;
			if(no == 0) count++;
			for (int j = 0; j < no; ++j) {
				cin >> x; 
				g.at(x).push_back(i);
				rg.at(i).push_back(x);
			}
		}
	//	 print(g);
		if (count > 1) cout << "0\n";
		else {
			cout << solve() << endl;
		}
	}
	return 0;
}