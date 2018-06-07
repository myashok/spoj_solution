#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int n, i, j, k, l;
//	long long int n;
	scanf("%lld", &j);
	for (i = 0; i < j; ++i) {
		scanf("%lld", &n);
		k = 4+4*n;
		l = ((sqrt(k))-2)/2;
		printf("Case %lld: %lld\n",i+1, l);
			
		
	}
	return 0;
}
