#include <stdio.h>

int main(void) {
	// your code goes here
	long long int i, k, l,result=0;
	scanf("%lld", &l);
	for (i = 0; i < l; ++i) {
		scanf("%lld", &k);
		result = result ^ k;
	}
	printf("%lld\n",result);
	
	return 0;
}
