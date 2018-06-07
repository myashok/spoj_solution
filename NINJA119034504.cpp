#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n+1], b[n+1], c[n+1];
		c[0] = -1;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int j = 1; j <= n; ++j)
			cin >> b[j];
		int mn;
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			 mn = min(a[i], b[i]);
			 if (mn >= c[i-1]) {
			 	c[i] = mn;
			 }
			 else {
			 	if(((a[i]+b[i]) - mn) >= c[i-1]) c[i] = ((a[i]+b[i]) - mn);
			 	else {flag = false; break;} 
			 }
		}
		flag ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}