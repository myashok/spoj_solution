#include <stdio.h>

int main(void) {
	// your code goes here
	long long int i, j, t, sum,n, third, lthird, a, d;
	scanf("%lld", &t);
	for (i = 0; i < t; ++i) {
		scanf("%lld %lld %lld", &third, &lthird, &sum);
		n = (2 * sum)/(third+lthird);
		d = (lthird-third)/(n-5);
		a = third - 2*d;
		printf("%lld\n", n);
		for (j = 0; j < n; ++j){
			 long long int b = a+j*d;
		     printf("%lld ",b);
		}
		printf("\n");
	}
	return 0;
}
