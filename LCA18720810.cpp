#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first;
#define se second;
using namespace std;
const int BLACK = 1, WHITE = 0;
struct node {
	vector<int> children;
	int color;
	int parent, ancestor, rank;
	node() {
		parent = ancestor = -1;
		rank = 0;
		color = WHITE;
	}
	vector<pair<pair<int, int>, int> > query;
};
int ans[(int)1e3+1];
int n;
struct node *tree;
typedef struct node node;
//code goes here
void makeset(int i) {
	tree[i].parent = i;
	tree[i].rank = 0;
}
int find(int i) {
	if(tree[i].parent != i)
		return find(tree[i].parent);
	return i;
}
void Union(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);
	if(tree[xroot].rank > tree[yroot].rank)
		tree[yroot].parent = xroot;
	else if(tree[xroot].rank < tree[yroot].rank)
		tree[xroot].parent = yroot;
	else  {
		tree[yroot].parent = xroot;
		tree[xroot].rank++;
	}
}
void tarjan(int u) {
	makeset(u);
	int v;
	tree[u].ancestor = u;
	for(auto it = tree[u].children.begin(); it != tree[u].children.end(); ++it) {
	    v = *it; 
		tarjan(v);
		Union(u, v);
		tree[find(u)].ancestor = u;
	}
	tree[u].color = BLACK;
	 for(auto it = tree[u].query.begin(); it != tree[u].query.end(); ++it) {
	 	auto p = it->first;
	 	auto index = it->second;
	 	if(tree[p.second].color == BLACK) {
	 		ans[index] = tree[find(p.second)].ancestor;
	 	}
	 }
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t, childs, x, q, u, v;
	cin >> t;
	for(int cas = 1; cas <=t; ++cas) {
		cin >> n;
		tree = new node[n+1]();
		for (int i = 1; i <= n; ++i) {
			cin >> childs;
			for (int j = 1; j <= childs; ++j) {
				cin >> x;
				tree[i].children.pb(x);
			}
		}
		cin >> q;
		for (int i = 1; i <= q; ++i) {
			cin >> u >> v;
			tree[u].query.pb(mp(mp(u, v), i));
			tree[v].query.pb(mp(mp(v, u), i));
		}
		tarjan(1);
		cout << "Case " << cas << ":\n";
		for (int i = 1; i <= q; ++i)
			cout << ans[i] << endl;
			
		delete[] tree;
	}
	return 0;
}