#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
vector<tuple<int , int, int > > g; // cost node;
int n, e, total;
vector<pair<int, int> > pr; //parent, rank;
int find(int i) {
	if(pr[i].fi == i) return i;
	else return find(pr[i].fi);
}

void Union(int x, int y) {
	int xr = find(x);
	int yr = find(y);
	if(pr[xr].se < pr[yr].se) 
		pr[xr].fi = yr;
	else if(pr[yr].se < pr[xr].se) 
		pr[yr].fi = xr;
	else {
		pr[yr].fi = xr;
		pr[xr].se++;
	}
}
int kruskal() {
	sort(g.begin(), g.end());
	pr.clear();
	pr.resize(n);
	for (int i = 0; i < n; ++i) {
		pr[i].fi = i;
		pr[i].se = 0;
	}
	// for (int i = 0; i < n; ++i) {
	// 	cout << pr[i].fi << " ";
	// 	cout <<  pr[i].se << endl;
	// }
	int ans = 0, c, u, v, ur, vr;
	for (auto it = g.begin(); it != g.end(); ++it) {
		 c = get<0>(*it);
		 u = get<1>(*it);
		 v = get<2>(*it);
		 ur = find(u);
		 vr = find(v);
		 if(vr != ur) {
		 	ans += c;
		 	Union(ur, vr);
		 }
	}
	// for (int i = 0; i < n; ++i) {
	// 	cout << pr[i].fi << " ";
	// 	cout <<  pr[i].se << endl;
	// }
	cout << (total - ans) << endl;
} 
int  main() {
	// your code goes here
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int u, v, c;
	while(1) {
		cin >> n  >> e;
		g.clear();
		total = 0;
		if (n == 0 && e == 0) break;
		for (int i = 0; i < e; ++i) {
			cin >> u >> v >> c;
			total += c;
			g.push_back({c, u, v});
		}
		kruskal();
	}
	return 0;
}