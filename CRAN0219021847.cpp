#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n], sum[n+1];
		sum[0] = 0;
		map<int, int> count;
		count[sum[0]]++;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum[i+1] = arr[i] + sum[i];
			count[sum[i+1]]++;
		}
		long long ans = 0;
		long long x;
		for (auto it = count.begin(); it != count.end(); ++it) {
			x = it->second;
		//	cout << it->first<< " " << x << endl;
			ans += (x*(x-1))/2;
		}
		cout << ans << endl;
	}
	return 0;
}