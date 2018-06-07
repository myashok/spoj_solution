#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int E, l;
		cin >> E >> l;
		int a[l], t[l];
		int dp[E+1];
		for (int i = 0; i < l; ++i) 
			cin >> a[i];
		for (int i = 0; i < l; ++i) 
			cin >> t[i];
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < l; ++i) {
			for (int e = 0; e <= E; ++e) {
				if(e < a[i]) continue;
				dp[e] = max(dp[e], dp[e-a[i]] + t[i]);
			}
		}
		int ans = -1;
		for (int i = 0; i <= E; ++i) {
			if (ans < dp[i]) ans = dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}