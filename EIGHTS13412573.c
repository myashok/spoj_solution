#include <stdio.h>

int main(void) {
	// your code goes here
	long long int n, i, j, k;
	scanf("%lld", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &j);
		k = 192 + 250*(j-1);
		printf("%lld\n",k);
	}
	return 0;
}
