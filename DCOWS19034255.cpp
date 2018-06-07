#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	cin >> n >> m;
	int a[n+1], b[m+1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int j = 1; j <= m; ++j)
		cin >> b[j];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	long long dp[n+1][m+1];
	for (int i = 1; i <= m; ++i)
		dp[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = LLONG_MAX - (int)1e7;
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = min(dp[i][j-1],abs(a[i]-b[j]) + dp[i-1][j-1]);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}