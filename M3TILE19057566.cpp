#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	//int t; cin >> t;
	int n;
	int dp[31] = {0};
	dp[0] = 1;
	for (int i = 1; i <= 30; ++i) {
		if(i & 1) continue;
		else {
			dp[i] = dp[i-2]*3;
		//	 cout << i << " " << dp[i] << endl;
			int t = i-4;
			for (int j = t; j >= 0; j -= 2)
			 	dp[i] = dp[i] + 2*dp[j];
		}
	}
	while(1) {
		cin >> n;
	//	cout << n << endl;
		if(n == -1) break;
		cout << dp[n] << endl;
	}
	
	return 0;
}