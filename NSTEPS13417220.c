#include <stdio.h>
#include <string.h>
int main(void) {
	// your code goes here
	long long int n, a,b,i;
	scanf("%lld", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld %lld", &a, &b);
		if((a == b )&& (a%2 == 0))
			printf("%lld\n", 2*a);
		else if((a == b )&& (a%2 != 0))
			printf("%lld\n", (2*a)-1);
		else if((a == (b+2 ))&& (a%2 ==0))
			printf("%lld\n",(a+b));
		else if ((a == (b+2)) &&(a%2 != 0)) {
			printf("%lld\n", (a+b)-1);
		}
		else printf("No Number\n");
		}
	return 0;
}
