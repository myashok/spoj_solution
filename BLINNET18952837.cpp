#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int> > g;
map<string, int> mymap;
int n;
void clearAndResize(int n) {
	g.clear();
	mymap.clear();
	int s = n+1;
}
// A structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
     else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int kruskal() {
	struct subset subsets[n+1];
    for (int v = 1; v < n+1; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int ans = 0;
    int e = 0, i = 0;
 //   cout << ans << endl;
    while(e < n-1) {
    	auto u = g[i++];
    	int x = find(subsets, get<1>(u));
    	int y = find(subsets, get<2>(u));
    	if (x != y) {
    		ans += get<0>(u);
    		Union(subsets, x, y);
    		e++;
    	}
    }
    return ans;
 
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
				g.push_back({c, i+1,  u});
			}
		}
		sort(g.begin(), g.end());
		cout << kruskal() << endl;
		
	}
	return 0;
} 