#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n & 1)
			cout << "Sorry Shaktiman\n";
		else 
			cout << "Thankyou Shaktiman\n";
	}
	return 0;
}