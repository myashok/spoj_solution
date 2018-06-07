#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	long long n;
	while(t--) {
		cin >> n;
		if(n%3 == 0) cout << "Ragini\n";
		else cout << "Hemlata\n";
	}
	return 0;
}