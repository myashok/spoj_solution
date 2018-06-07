#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int n, b;
	int cnt = 0;
	while(t--) {
		cin >> n >> b;
		int arr[n+1];
		for (int i = 1; i <= n; ++i) cin >> arr[i];
		int dp[n+1][b+1];
		for (int i = 0; i <= n; ++i) {
			for (int w = 0; w <= b; ++w) {
				if(i == 0 || w == 0) dp[i][w] = 0;
				else if(w >= arr[i]) dp[i][w] = max(dp[i-1][w - arr[i]] + arr[i], dp[i-1][w]);
				else dp[i][w] = dp[i-1][w];
			}
		}
		printf("Scenario #%d: %d\n", ++cnt, dp[n][b]);
	}
	return 0;
}