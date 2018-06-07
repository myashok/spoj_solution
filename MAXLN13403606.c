#include <stdio.h>

int main(void) {
  long int n, r, i, j, k, l;
	double ans;
	scanf("%ld", &n);
	for(i=0;i<n;++i) {
		scanf("%ld", &r);
		
		ans =(long long)4*r*r + 0.25;
		printf("Case %d: %.2lf\n",i+1,ans);
	}
	return 0;
}


