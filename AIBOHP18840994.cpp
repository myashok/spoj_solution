#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;
	string s, rs;
	cin >> t;
	while(t--) {
		cin >> s;
		rs = s;
		reverse(rs.begin(), rs.end());
		int n = s.length();
		int dp[n+1][n+1];
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if(i == 0 || j == 0)
					dp[i][j] = 0;
				else if(s[i-1] == rs[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else 
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout << (n - dp[n][n]) << endl;
	}
	return 0;
}