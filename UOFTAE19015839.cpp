#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  mn[201], mx[201];
long long dp[201][201];
const ll mod = (ll)1e9+7;
ll solve(ll  n, ll  m) {
	if (m < 0) return 0;
	if(n == 0) {
		if(m == 0) return 1;
		else return 0;
	}
	if(dp[n][m] != -1) return dp[n][m];
	ll ans = 0;
	for (ll  i = mx[n]; i >= mn[n]; --i) {
		ans += solve(n-1, m - i);
		ans %= mod;
	}
	return dp[n][m] = ans;
}
int  main(void) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll  t;
	cin >> t;
	ll  n, m;
	while (t--) {
		cin >> n >> m;
		for (ll  i = 1; i <= n; ++i) {
			cin >> mn[i] >> mx[i];
		}
		memset(dp, -1, sizeof(dp));
		solve(n, m);
		cout << dp[n][m] << endl;
	}
} 