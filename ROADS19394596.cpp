#include <bits/stdc++.h>
using namespace std;
//int s[10001], d[10001], l[10001], t[10001];
typedef tuple<int, int, int> tiii;
int k, n, r;
vector<vector<tiii> >  g;
void solve() {
	priority_queue<tiii, vector<tiii>, greater<tiii> > Q;
	Q.push({0, 0, 1});
	int d, vl, vt;
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();
		int s = get<2>(u);
		int l = get<0>(u);
		int t = get<1>(u);
		if(s == n) {
			cout << l << endl;
			return;
		}
		for (auto it = g[s].begin(); it < g[s].end(); ++it) {
			d  = get<2>(*it);
			vl = get<0>(*it);
			vt = get<1>(*it);
			if(vt + t <= k) {
				Q.push({vl+ l, vt + t, d});
			}
		} 
		
	}
	cout << "-1\n";
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		cin >> k >> n >> r;
		int s, d, l, t;
		g.clear();
		g.resize(10001);
		for (int i = 0; i < r; ++i) {
			cin >> s >> d >> l >> t;
			g[s].push_back({l, t, d});
		}
		solve();
	}
	return 0;
}