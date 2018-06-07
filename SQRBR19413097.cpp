#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[40][40];
bool open[40];
long long solve(int pos, int opcount) {
	if(opcount < 0) return 0;
	if(pos == n) return opcount == 0;
	long long &res  = dp[pos][opcount];
	if(res != -1) return res;
	if(open[pos])
	    return res = solve(pos+1, opcount+1) ;
    return res = solve(pos+1, opcount+1) + solve(pos + 1, opcount-1);
}
int main() {
	// your code goes heres
	int t, k; cin >> t;
	while(t--) {
		cin >> n >> k;
		n <<= 1;
		int x;
		memset(open, 0, sizeof(open));
	    memset(dp, -1, sizeof(dp));
		for (int i = 0; i < k; ++i) {
			cin >>  x;
			open[x-1] = true;
		}
		cout << solve(0, 0) << endl;
	}
	return 0;
}