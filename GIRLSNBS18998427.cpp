#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	while(1) {
		int a, b;
		cin >> a >> b;
		if(a == -1 and b == -1) break;
		if(a == 0) cout << b << endl;
		else if(b == 0) cout << a << endl;
		else {
			cout << (ceil(max(a,b)/ (float)(min(a,b)+1))) << endl;
		}
	}
	return 0;
}