#include <iostream>
using namespace std;
int arr[21][21];
typedef long long ll;
int n;
long long dp[1<<21];


int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
			}
		}
		dp[0] = 1;
		for (int i = 1; i < (1 << n); ++i) {
			dp[i] = 0;
			int j = __builtin_popcount(i);
			for(int k = 0; k < n; ++k) {
				if(arr[j-1][k] && (i & (1<<k))) 
					dp[i] += dp[i & ~(1<<k)];
			}
		}
		cout << dp[(1<<n)-1] << endl;
	}
	
	return 0;
}