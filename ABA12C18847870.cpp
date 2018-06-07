#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int n, r;
	while(t--) {
		cin >> n >> r;
		int p[r+1], dp[r+1];
		for (int i = 0; i < r; ++i)
			cin >> p[i];
		dp[0] = 0;
		for (int i = 1; i <= r; ++i) {
			dp[i] = INT_MAX;
			for(int j = 0; j < i; ++j) {
				dp[i] = min(dp[i], p[j] + dp[i-j-1]);
			}
		}
		if(dp[r] <= 0)
			cout << "-1\n";
		else
		cout << dp[r] << endl;
	}
	return 0;
}