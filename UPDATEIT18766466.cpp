#include <bits/stdc++.h>
using namespace std;
#define si(x) scanf("%lld", &x)
long long BIT[(int)1e4+2];
long long n, u, q;
void update(long long i, long long val) {
	for(; i <= n; i += i & -i ) {
		BIT[i] += val;
	}	
}
void update(long long l, long long r, long long val) {
	update(l, val);
	update(r+1, -val);
}
long long query(long long i) {
	long long sum = 0;
	for(; i >= 1; i -= i & -i) 
		sum += BIT[i];
	return sum;
}
int main() {
	long long t, l, r, val;
	si(t);
	while(t--) {
		memset(BIT, 0, sizeof(BIT));
		si(n);
		si(u);
		while(u--) {
			si(l);si(r);si(val);
			update(l+1, r+1, val);
		}
		si(q);
		while(q--) {
			si(l);
			printf("%lld\n", query(l+1));
		}
	}
	return 0;
}