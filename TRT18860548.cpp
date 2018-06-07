#include <iostream>
using namespace std;
int dp[2001][2001], arr[2001];
int solve(int ss, int se, int l) {
	if(ss == se) {
		return dp[ss][se] = arr[ss]*l;
	}	
	int &res = dp[ss][se];
	if(res != 0)
		return res;
	res = max(arr[ss]*l + solve(ss+1, se, l+1), solve(ss, se-1, l+1) + arr[se]*l);
	return res;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << solve(0, n-1, 1) << endl;
	return 0;
}