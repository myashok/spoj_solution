#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr+n);
		int mn = INT_MAX;
		for (int i = 0; i + k - 1 < n; ++i) {
			mn = min(mn, arr[i+k-1] - arr[i]);
		}
		cout << mn << endl;
	}
	return 0;
}