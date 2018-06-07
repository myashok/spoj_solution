#include <stdio.h>

int main(void) {
	// your code goes here
	long long int i, j, t, sum,n, x,y, a, d,check;
	scanf("%lld", &t);
	for (i = 0; i < t; ++i) {
		scanf("%lld %lld %lld", &x, &y, &sum);
		for (n = 7; n >= 0; n++)  {
			check = (n*((2*x)-(4*(y-x)/(n-6))+(n-1)*(y-x)/(n-6)))/2;
			if(check == sum)
				break;
		}
		d = (y-x)/(n-6);
		a = x - 2*d;
		printf("%lld\n", n);
		for (j = 0; j < n; ++j){
			 long long int b = a+j*d;
		     printf("%lld ",b);
		}
		printf("\n");
	}
	return 0;
}

