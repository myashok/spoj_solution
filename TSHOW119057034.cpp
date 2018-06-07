#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	vector<ll> twos;
	ll n = (ll)1e18;
	for (ll i = 1; i <= n; i *= 2) 
		twos.push_back(i);
	ll t; cin >> t;
	ll k, last;
	while(t--) {
		cin >> k;
		ll i = 1;
		for (; k > twos[i]; ++i) {
			k -= twos[i];
		}
		last = k;
		for (ll j = i-1; j >= 0; --j) {
			if(last > twos[j]) {
				cout << "6";
				last -= twos[j]; 
			}
			else {
				cout << "5";
			}
		}
		cout << endl;
	}
	return 0;
}