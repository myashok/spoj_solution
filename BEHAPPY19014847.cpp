#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int  mn[201], mx[201];
long long int dp[201][201];
const long long int MOD =  1000000007;
ll solve(ll  n, ll  m) {
	if(n == 0) {
		if(m == 0) return 1;
		else return 0;
	}
	if(dp[n][m] != -1) return dp[n][m];
	ll ans = 0LL;
	for (int  i = mx[n]; i >= mn[n]; --i) {
		ans += solve(n-1, m - i);
	}
	dp[n][m] = ans;
	return dp[n][m];
}
int  main(void) {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll  t;
//	cin >> t;
	ll  n, m;
	while (1) {
		cin >> n >> m;
		if( n == 0 && m == 0) 
			break;
		for (int  i = 1; i <= n; ++i) {
			cin >> mn[i] >> mx[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(n, m)<< endl;
	}
	return 0;
}