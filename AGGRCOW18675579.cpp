#include <bits/stdc++.h>
using namespace std;
int stall[(int)1e6+1], n, c;
bool possible(int dist) {
	int lastpos = stall[0];
	int remaining = c-1;
	for(int i = 1; i < n; ++i) {
		if(stall[i] - lastpos >= dist)
			remaining--, lastpos = stall[i];
	}
	return (remaining <= 0);
}
int solve()  {
	sort(stall, stall+n);
	int start = 0, end = stall[n-1] - stall[0] + 1;
	int mid = 0, ans = 0;
	while(start <= end) {
		mid = (end - start)/2 + start;
		(possible(mid)) ? (ans = mid, start = mid + 1): end = mid - 1;
		
	}
	return ans;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> c;
		for (int i = 0; i < n; ++i) 
			cin >> stall[i];
		cout << solve() << endl;
	}
	return 0;
}