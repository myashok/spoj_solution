#include <iostream>
using namespace std;

int main() {
	// your code goes here
	while(1) {
		int n;
		cin >> n;
		if(n == -1) break;
		int arr[n], sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		if(sum % n == 0) {
			int avg = sum/n;
			int count = 0;
			for(int i = 0; i < n; ++i) {
				if(arr[i] > avg)
					count += (arr[i] - avg);
			}
			cout << count << endl;
		}
		else {
			cout << "-1\n";
		}
		
	}
	return 0;
}