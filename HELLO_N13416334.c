#include <stdio.h>
#include <string.h>
int main(void) {
	// your code goes here
	long long int n, i, j, l, sum;
	scanf("%lld", &n);
	char str[n][100000];
	for (i = 0; i < n; ++i) {
		scanf("%lld", &l);
		for (j = 0; j < l; ++j) {
			scanf("%s", str[j]);
			}
		if(l == 0) printf("Hello!\n");
		if (l == 1)
			printf("Hello %s!\n",str[0]);
		if(l > 1) {
			printf("Hello ");
			for (j = 0; j < l-2;++j)
				printf("%s, ", str[j]);
			printf("%s and %s!\n",str[l-2],str[l-1]);
		}
			
		
	}
	return 0;
}
