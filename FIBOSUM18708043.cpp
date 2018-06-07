#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9+7;
map<ll, ll> f;
ll fib(ll n) {
	if(n < 2) {
		f[n] = n;
		return n;
	}
	if(f[n])
		return f[n];
	ll k = n&1 ? (n+1)/2:n/2;
	f[n] = n&1 ? (((fib(k-1))%mod*(fib(k-1)%mod))%mod + ((fib(k))%mod*(fib(k)%mod))%mod)%mod :
	(((2*fib(k-1))%mod + (fib(k))%mod)%mod * (fib(k)%mod))%mod;
	return f[n];
}
int main() {
	int n;
	ll l , r, ans;
	cin >> n;
	while(n--) {
		cin >> l >> r;
		l++; r+=2;
	//	cout << fib(r+2) << " " << fib(l-1) << endl;
		ans = (fib(r) - fib(l) + mod)%mod;
		cout << ans << endl;
	}
	return 0;
}