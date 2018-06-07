#include <cstdio>
long long int arr[(int)1e5+10], dp[(int)1e5+10];
typedef long long ll;
inline ll max(ll a, ll b) {
	if(a >= b) return a;
	return b;
}
int main() {
	// your code goes here
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &arr[i]);
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = -1;
			dp[i] = max(dp[i], (i+2 < n ? dp[i+2] : 0) + arr[i]);
			dp[i] = max(dp[i], (i+4 < n ? dp[i+4] : 0) + arr[i] + (i + 1 < n ? arr[i+1]: 0));
			dp[i] = max(dp[i], (i+6 < n ? dp[i+6] : 0) + arr[i] +(i + 1 < n ? arr[i+1]: 0) + (i + 2 < n ? arr[i+2]: 0));
			
		}
		printf("%lld\n", dp[0]);
	}
	return 0;
}