#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
using namespace std;
 
int main() {
	// your code goes here
	int n, m;
	si(n); si(m);
	int arr[n][m+1];
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= m; ++j)
			si(arr[i][j]);
	vector<vector<int> > dp(n, vector<int>(m+2, INT_MAX));
	for (int i = 1; i <= m; ++i) {
		dp[0][i] = arr[0][i];
	//	cout << dp[0][i] << " ";
	}
//	cout << endl;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) + arr[i][j];
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	
	int ans = *min_element(dp[n-1].begin(), dp[n-1].end());
	printf("%d\n",ans);

	return 0;
} 