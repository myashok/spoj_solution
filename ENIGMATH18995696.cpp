#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a, b;
	while(t--) {
		cin >> a >> b;
		int x = __gcd(a, b);
		cout << (b / x) << " " << (a/x) << endl; 
	}
	return 0;
}