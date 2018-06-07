#include <bits/stdc++.h>
using namespace std;
int solve(int c[], int n) {
	int inc[n+1];
	int length = 0;
	for (int i = 0; i < n; ++i) {
		int low = 1;
		int high = length;
		while(low <= high) {
			int mid = (low+high)/2;
			if(c[inc[mid]] < c[i])
				low  = mid + 1;
			else high = mid - 1;
		}
		int pos = low;
		inc[pos] = i;
		if (pos > length)
			length = pos;
	}
	return length;
	
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n], c[n], hash[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			hash[a[i]] = i;
		}
		for (int i = 0; i < n; ++i) 
			cin >> b[i];
		for (int i = 0; i < n; ++i) 
			c[i] = hash[b[i]];
		cout << solve(c, n) << endl;
	}
	return 0;
}