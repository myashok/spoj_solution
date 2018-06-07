#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int n;
	bool dp[101][(int)1e5+1];
	int ans = 0;
	int arr[101];
	while(t--) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i) 
			cin >> arr[i], sum += arr[i];
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = true;
		for (int i = 1; i <= sum; ++i)
			dp[0][i] = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= sum; ++j) {
				if(arr[i] > j)
					dp[i][j] = dp[i-1][j];
				else {
					dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
				}
			}
		}
		int ans = 0;
		for (int j = 1; j <= sum; ++j)
			if(dp[n][j])
				ans += j;
		cout << ans << endl;
	}
	
	return 0;
}