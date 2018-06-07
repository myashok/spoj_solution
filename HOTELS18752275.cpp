#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	long long int m, arr[(int)3e5+1] = {0};
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%lld", &arr[i]);
	long long mx = INT_MIN, sum = 0;
	for (int i = 0, j = 0; i < n || j < n;) {
		if(sum + arr[i] <= m) {
			sum += arr[i++];
		}
		else {
			sum -= arr[j++];
		}
		if(sum <= m && sum > mx)
			mx = sum;
	}
	printf("%lld\n", mx);
	return 0;
}