#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9+7;
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int n = str.length();
		vector<int> last(256, -1);
		long long dp[n+1];
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i-1] << 1;
			dp[i] %= mod;
			if(last[str[i-1]] != -1) {
				dp[i] = (dp[i] - dp[last[str[i-1]]] + mod)%mod;
			}
			last[str[i-1]] = i-1;
		}
		// for (int i = 0; i <= n; ++i)
		// 	cout << dp[i] << " ";
		// cout << endl;
		cout << dp[n] << endl;
	}
	return 0;
}