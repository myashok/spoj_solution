#include <stdio.h>

int main(void) {
	// your code goes here
	int n, i, j, m;
	scanf("%d", &n);
	long long int sum, l ,k;
	for (i = 0; i < n; ++i) {
		sum = 0;
		scanf("%lld", &l);
		sum =((((l*(l+1)*(2*l+1))/6) +((l*(l+1))/2)))/2;
		k = l/2;
		if (l%2==0) {
		sum = sum + (((4*k*(k+1)*(2*k+1))/6) - ((2*k*(k+1))/2))/2;
		}
		else  {
			
			sum = sum + (((4*k*(k+1)*(2*k+1))/6) + ((2*k*(k+1))/2))/2;
		}
		printf("%lld\n", sum);
	}
	return 0;
}

