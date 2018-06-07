#include <bits/stdc++.h>
using namespace std;
string s;
long long int dp[(int)5e3+2];
long long  solve()  {
	dp[0] = 1;
	int n = s.length();
	int onedigit, twodigit;
	for (int i = 1; i < n; ++i) {
		 dp[i] = 0;
		 onedigit = s[i] - '0';
		 twodigit = (s[i-1] -'0') * 10 + onedigit;
		 if(onedigit)
		 	dp[i] += dp[i-1];
		 if(twodigit > 9 && twodigit < 27)
		 	dp[i] += dp[i-2 > 0 ? i-2: 0 ];
	//	 cout << twodigit << " " << dp[i] << endl;
	}
	// for (int i = 0; i < n; ++i) {
	//   cout << dp[i] << " ";
	// }
	// cout << endl;
	return dp[n-1];
}
int main() {
	ios::sync_with_stdio(false);
    while(1) {
		cin >> s;
		if(s == "0")
			break;
		cout << solve() << endl;
	}
	return 0;
}