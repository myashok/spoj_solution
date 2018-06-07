#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
    long long int n, i, j, k, l ;
	scanf("%lld", &n);
	long double ans, one, two, three, four, five, second;
	for (i = 0; i < n; ++i) {
		scanf ("%lld%lld%lld", &j, &k, &l);
		one = (long double)j*k;
		two = (long double) k*l;
		three=(long double)l*j;
		four = (long double)l * j * k;
		five = (long double)l + j + k;
		ans = (long double)(one + two + three)/four;
	//	printf("%Lf\n",ans);
		second = (long double)five / four;
	//	printf("%Lf\n",second);
		second = 2*sqrt(second);
	//	printf("%Lf\n",second);
		ans = 1/( ans + second);
		printf("%Lf\n", ans);
	}
	return 0;
}
