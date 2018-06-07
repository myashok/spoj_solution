#include <bits/stdc++.h>
#define pb push_back
#define vvvi vector<vector<vector<int> > >
using namespace std;
const int A = 0, W = 1, F = 2;
int He, Ar;
const int row = 1010, col = 1500, type = 3;
int Water(int He, int Ar, vvvi &dp);
int Fire(int He, int Ar, vvvi &dp);
int Air(int He, int Ar, vvvi& dp) {
	if(He <= 0 || Ar <= 0)
		return 0;
	int &res = dp[He][Ar][A];
	if(res != -1)
		return res;
	return res = max(Water(He+3, Ar+2, dp), Fire(He+3, Ar+2, dp)) + 1;
}
int Water(int He, int Ar, vvvi& dp) {
	if(He <= 5 || Ar <= 10)
		return 0;
	int &res = dp[He][Ar][W];
	if(res != -1)
		return res;
	return res = max(Air(He-5, Ar-10, dp), Fire(He-5, Ar-10, dp)) + 1;
}
int Fire(int He, int Ar, vvvi& dp) {
	if(He <= 20 || Ar <= 0)
		return 0;
	int &res = dp[He][Ar][F];
	if(res != -1)
		return res;
	return res = max(Water(He-20, Ar+5, dp), Air(He-20, Ar+5, dp)) + 1;
}
int solve(int He, int Ar, vvvi &dp) {
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < type; ++j)
			dp[i][0][j] = 0;
	for(int i = 0; i < col; ++i)
		for(int j = 0; j < type; ++j)
			dp[0][i][j] = 0;
	int air, water, fire;
	air = Air(He, Ar, dp);
	water = Water(He, Ar, dp);
	fire = Fire(He, Ar, dp);
	return max(air, max(water, fire));
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	clock_t start, end;
	start = clock();
	while(t--) {
		cin >> He >> Ar;
		vector<vector<vector<int> > > dp(row, vector<vector<int>>(col, vector<int>(type, -1))); 
		cout << solve(He, Ar, dp) << endl;
	}
	end = clock();
	double ans = ((double)end - start)/CLOCKS_PER_SEC;
//	cout << ans << endl;
	return 0;
}