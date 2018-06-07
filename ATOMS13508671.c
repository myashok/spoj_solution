#include <stdio.h>
int main (void) {
	long long int i, j,mul, p, n, k, m,t=0;
	scanf("%lld", &p);
	while(p--) {
		scanf("%lld %lld %lld", &n, &k, &m);
		mul=n;
		t = 0;
		if(k <= m/n) {
			t++;
			mul = n*k;
		while(k <= m/mul) {
			mul*=k;
			t++;
		}
		}
		printf("%lld\n",t);
	}
	return 0;
}