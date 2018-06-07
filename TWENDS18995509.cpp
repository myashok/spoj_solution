#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > dp;
int arr[1001];
int n;
int solve(int i,int j) {
	if(i == j) {
		return dp[i][j] = arr[i];
	}
	else if(i > j) return 0;
	int &res = dp[i][j];
	if (res != -1) return res;
	int val1, val2;
	val1 = arr[i+1] >= arr[j] ? arr[i] + solve(i+2, j): arr[i] + solve(i+1, j-1);
	val2 = arr[i] >= arr[j-1] ? arr[j] + solve(i+1, j-1): arr[j] + solve(i, j-2);
	return res = max(val1, val2);
}
int main(void) {
	int count = 0;
	while(1) {
		cin >> n;
		count++;
		if (n == 0) break;
		dp.clear();
		dp.resize(n+1, vector<int> (n+1, -1));
		int total = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			total += arr[i];
		}
		int ans = solve(1, n);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count, 2*ans - total);
	//	In game m, the greedy strategy might lose by as many as p points.
	}
}