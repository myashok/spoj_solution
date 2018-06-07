#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int , int> > g; //cost src dest
int n, c;
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
// The main function to construct MST using Kruskal's algorithm
int kruskal() {
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
    // Allocate memory for creating V ssubsets
    struct subset subsets[n+1];
    // Create V subsets with single elements
    for (int v = 1; v <= n; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int ans = 0;
    while (e < n - 1)
    {
        auto u = g[i++];
        int x = find(subsets, get<1>(u));
        int y = find(subsets, get<2>(u));
        if (x != y) {
            ans += get<0>(u);
            Union(subsets, x, y);e++;
        }
    }
    return ans;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		g.clear();
		int k;
		cin >> c >> n >> k;
		int u, v, len;
		for (int i = 0; i < k; ++i) {
			cin >> u >> v >> len;
			g.push_back({c*len, u, v});
		}
		sort(g.begin(), g.end());
		cout << kruskal() << endl;
	}
	return 0;
}