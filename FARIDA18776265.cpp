#include <bits/stdc++.h>
#define si(x) scanf("%lld", &x);
using namespace std;

int main() {
	// your code goes here
	int t;
	si(t);
	int c = 1;
	while(t--) {
		int n;
		si(n);
		long long arr[n];
		long long dp[n+1];
		for (int i = 0; i < n; ++i)
			si(arr[i]);
		dp[0] = 0;
		dp[1] = arr[0];
	//	cout << dp[1] << endl;
		for (int i = 2; i <= n; ++i) {
			dp[i] = max(dp[i-1], arr[i-1] + dp[i-2]);
		}
		printf("Case %d: %lld\n",c,  dp[n]);
		c++;
	}
	return 0;
}