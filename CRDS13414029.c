#include <stdio.h>

int main(void) {
	// your code goes here
	long long int n, i, j, l, sum;
	scanf("%lld", &n);
	for (i = 1; i <= n; ++i) {
		sum = 0;
		scanf("%lld", &l);
		sum = ((l*(2*3+(l-1)*3))/2)-l;
		printf("%lld\n",sum%1000007);
	}
	return 0;
}
