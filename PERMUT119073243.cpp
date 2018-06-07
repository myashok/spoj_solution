#include <bits/stdc++.h>
using namespace std;
int main() {
	int dp[100][13] = {0};
	int t;
	cin >> t;
	int n, k;
	while(t--) {
		cin >> n >> k;
		for (int i = 0; i <= k; ++i) 
			dp[i][0] = 0;
			
		for (int i = 0; i <= n; ++i) 
			dp[0][i] = 1;
		
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = 0;
				for (int k = i, l = 1; k >= 0 && l <= j; --k, ++l) 
					dp[i][j] += dp[k][j-1];
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}