#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
using namespace std;

int main() {
	// your code goes here
	int t;
	si(t);
	int n, m;
	while(t--) {
		si(n); si(m);
		int arr[n][m+1];
		for (int i = 0; i < n; ++i)
			for (int j = 1; j <= m; ++j)
				si(arr[i][j]);
		vector<vector<int> > dp(n, vector<int>(m+2, 0));
		for (int i = 1; i <= m; ++i) {
			dp[0][i] = arr[0][i];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) + arr[i][j];
			}
		}
		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 1; j <= m; ++j)
		// 		printf("%2d ", dp[i][j]);
		// 	cout << endl;
		// }
		int ans = *max_element(dp[n-1].begin(), dp[n-1].end());
		//cout << ans << endl;
		printf("%d\n",ans);
	}
	return 0;
}