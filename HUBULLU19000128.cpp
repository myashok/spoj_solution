#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a, b;
	while(t--) {
		cin >> a >> b;
		if(b == 0) cout << "Airborne wins.\n";
		else cout << "Pagfloyd wins.\n"; 
	}
	return 0;
}