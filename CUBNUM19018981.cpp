#include <bits/stdc++.h>
using namespace std;
int dp[(int)1e5+2];
int cnt;
void solve() {
	vector<int> wt;
	int W = (int)1e5+1;
	for(int i = 1; (i*i*i) <= W; ++i) {
		wt.push_back(i*i*i);
	}
   cnt = wt.size();
   fill(dp, dp+W, 1000000);
   dp[0] = 0;
   dp[1] = 1;
   for (int i = 0; i < cnt; i++) {
       for (int w = 0; w <= W; w++) {
           if(w < wt[i]) continue;
           dp[w] = min(dp[w], 1 + dp[w-wt[i]]);
       }
   }
 
}
int main() {
	// your code goes here
	int n;
	solve();
	int i = 1;
	while(scanf("%d", &n) != EOF) {
		printf("Case #%d: ", i);
		cout << dp[n] << endl;
		i++;
	}
	return 0;
}