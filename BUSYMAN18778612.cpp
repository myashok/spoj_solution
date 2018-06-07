#include <bits/stdc++.h>
#define si(x) scanf("%d", &x)
using namespace std;

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--) {
		int n ; si(n);
		vector<pair<int, int> > FS(n);
		for (int i = 0; i < n; ++i) {
			si(FS[i].second);
			si(FS[i].first);
		}
		sort(FS.begin(), FS.end());
		int res = 1;
		auto k = FS[0];
		for (auto it = next(FS.begin()); it != FS.end(); ++it) {
			auto u = *it;
			if(u.second >= k.first) {
				res++;
				k = u;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}