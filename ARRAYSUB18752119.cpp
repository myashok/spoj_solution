#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, k;
	int arr[(int)1e5+1];
	cin >> n;
	assert(n>= 1 and n <= (int)1e5);
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	cin >> k;
	int mx = *max_element(arr, arr+k);
	cout << mx << " ";
	for(int i = 1; i <= n - k; ++i) {
		 if(mx != arr[i-1] && arr[i+k-1] <= mx)
		 	cout << mx <<  " ";
		 else
		    cout << (mx = *max_element(arr + i, arr + i + k)) << " ";
	}
	cout << endl;
	return 0;
}