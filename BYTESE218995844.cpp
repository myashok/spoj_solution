#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t, n;
	cin >> t;
	int l, r;
	while(t--) {
		cin >> n;
		map<int, int> mymap;
		for (int i = 1; i <= n; ++i) {
			cin >> l >> r;
			mymap[l]++;
			mymap[r]--;
		}
		int max = -1, temp = 0;
		for (auto it = mymap.begin(); it != mymap.end(); ++it) {
			temp += it->second;
			max = temp > max ? temp : max;
		}
		cout << max << endl;
	}
	return 0;
}