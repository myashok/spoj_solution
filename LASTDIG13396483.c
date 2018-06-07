#include <stdio.h>

int main(void) {
	// your code goes here
	long int n, i, j, k, l, a, b, m;
	scanf("%ld", &n);
	for (i = 0; i < n; ++i) {
		m = 1;
		scanf("%ld%ld", &a, &b);
		if (b == 0) {
			printf("1\n");
			continue;
		}
		j = a % 10;
		k = b % 4;
		if (k == 0)
			k+=4;
		for(l = 0; l < k; ++l){
			m = m * j;
		}
		printf("%d\n", m % 10);
	}
	return 0;
}
