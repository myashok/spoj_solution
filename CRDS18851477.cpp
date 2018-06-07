#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000007;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << ((3*((n*(n+1))/2)) - n)%mod << endl;
	}
	return 0;
}