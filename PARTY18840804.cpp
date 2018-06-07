#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int W, n;
	while(1) {
		cin >> W >> n;
		if(W == 0 && n == 0) break;
		pair<int, int> CF[n+1];
		for (int i = 1; i <= n; ++i)
			cin >> CF[i].fi >> CF[i].se;
		int dp[n+1][W+1];
		// for (int i = 1; i <= n; ++i)
		// 	cout << CF[i].fi << " " <<  CF[i].se << endl;
		for (int i = 0; i <= n; ++i) {
			for (int w = 0; w <= W; ++w) {
				if(i == 0 || w == 0)
					dp[i][w] = 0;
				else if(CF[i].fi <= w)
					dp[i][w] = max(dp[i-1][w], dp[i-1][w-CF[i].fi] + CF[i].se);
				else
					dp[i][w] = dp[i-1][w];
			}
	    }
	    pair<int, int> ans;
		int mx = -1;
		for (int w = 0; w <= W; ++w) {
			if(mx < dp[n][w]) {
				mx = dp[n][w];
				ans = make_pair(w, dp[n][w]);
			}
		}
		cout << ans.fi << " " << ans.se << endl;
	}
	return 0;
}