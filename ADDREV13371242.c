#include <stdio.h>

int main(void) {
	int n, i, a, b, sumrem, sum, revers, rever;
	scanf ("%d", &n);
	for (i = 0; i < n; ++i) {
		sum=0,sumrem=0,revers=0,rever=0;
		scanf ("%d %d", &a, &b);
		while (a > 0 ) {

			revers = 10*revers+a%10;
			a = a/10;


		}

		while (b > 0 ) {
			rever = 10*rever+b%10;
			b = b/10;

		}


		sum = revers + rever;

	
		while(sum > 0) {
			sumrem=sumrem*10+sum%10;
			sum = sum /10;

		}
		printf("%d\n",sumrem);
	}
	return 0;
}
