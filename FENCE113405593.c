#include <stdio.h>

int main(void) {
	// your code goes here
	int n, i, j, t=1;
	double ans;
	while(t++) {
		scanf("%ld", &n);
		if ( n == 0) 
		break;
		ans = n*n;
		ans =(float) ans/(2*3.141592);
		printf("%.2lf\n", ans);
	}
	return 0;
}

