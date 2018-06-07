#include <bits/stdc++.h>
using namespace std;
long long n;
map<long long, long long> dp;
long long  f(long long n)  {
	if(n <= 11) {
		dp[n] = n;
		return dp[n];
	}
	if(dp.find(n) != dp.end())
		return dp[n];
    dp[n] = max(f(n/2) + f(n/3) + f(n/4), n);
    return dp[n];
	
}
int main() {
	ios::sync_with_stdio(false);
	long long i = 0;
    while(scanf("%d", &n) != EOF) {
		cout << f(n) << endl;
	}
	return 0;
}