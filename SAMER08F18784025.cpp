#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	while(1) {
		long long n;
		cin >> n;
		if(n == 0) break;
		long long ans = 0;
		ans = ((n)*(n+1)*(2*n+1) )/ 6;
		cout << ans << endl;
	}
	return 0;
}