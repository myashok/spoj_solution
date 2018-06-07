#include <stdio.h>

int main(void) {
	// your code goes here
	long int n, i, j, t = 1;
	//double ans;
	while(t++) {
		j = 0;
		scanf("%ld",&n);
		if (n == 0) break;
		for (i = 1; i <= n; ++i) {
			j = j + i*i;
		}
		printf("%ld\n", j);
	}
	return 0;
}

