#include <bits/stdc++.h>
using namespace std;
bool isprime(long long sum) {
	for (int i = 2; i*i <= sum; ++i)
		if(sum % i == 0) return false;
	return true;	
}
bool check(int n) {
	map<int, long long int> mymap;
	int t = n;
	long long int sum = 1;
	for (int i = 2; i*i <= t; ++i) {
		if(n%i == 0)  {
			while(n%i == 0) {
				mymap[i]++;
				n /= i;
			}
		}
		if(mymap.find(i) != mymap.end()) {
			sum *= (pow(i, mymap[i]+1) - 1) / (i - 1);
		}
	}
	if(isprime(sum)) return true;
	return false;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		int ans = 0;
		l--;
		if(2 > l && 2 <= r) ans++;
		int temp = ceil((sqrt(l+1)));
		for (int i = temp > 1 ? temp: 2; i*i <= r; ++i) {
			if(check(i*i))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}