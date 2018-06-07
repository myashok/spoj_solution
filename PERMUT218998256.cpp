#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	while(1) {
		int n; cin >> n;
		if(n == 0) break;
		vector<int> a(n+1), b(n+1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[a[i]] = i;
		}
		if (a == b)
		 cout << "ambiguous\n";
		else
		 cout << "not ambiguous\n";
	}
	return 0;
}