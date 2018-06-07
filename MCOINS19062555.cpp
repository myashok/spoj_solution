#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int x, y, z, m;
	cin >> x >> y >> m;
	z = 1;
	bool dp[(int)1e6+1] = {false};
	int l = (int)1e6;
	dp[0] = false;
	int dx, dy;
	dx = dy = true;
	for (int i = 1; i <= l; ++i) {
		if(i >= x) dx = dp[i-x]; 
		if(i >= y) dy = dp[i-y]; 
		dp[i] = !(dp[i-z]) || !(dx) || !(dy);
		dx = dy = true; 
	}
	int n;
	while(m--) {
		cin >> n;
		if(dp[n]) cout << "A";
		else cout << "B";
	}
	cout << endl;
	return 0;
}