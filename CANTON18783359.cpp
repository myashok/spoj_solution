#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	int num, den, d;
	while(t--) {
		cin >> n;
		int i = 0;
		for ( ; ((i)*(i+1))/2 < n; ++i) {
	//		cout << ((i)*(i+1))/2 << " " << n << endl;
		}
	//	cout << i << endl;
		d = n - ((i)*(i-1))/2;
		if(i&1) {
		  num = 1 + (d-1);
		  den = i - (d-1);
		  printf("TERM %d IS %d/%d\n", n, den, num);
		}
		else {
			 num = 1 + (d-1);
			 den = i - (d-1);
			 printf("TERM %d IS %d/%d\n", n, num, den);
		}
	}
	return 0;
}