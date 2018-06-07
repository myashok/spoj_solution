#include <stdio.h>

int main(void) {
	// your code goes here
	 unsigned long long int n,a, ans=0;
	 int i, j,t;
	scanf("%llu", &n);
	for (i = 0; i < n; ++i) {
		ans=0;
		scanf("%d", &t);
		for (j = 0; j < t; ++j) {
			scanf("%llu",&a);
			ans = (ans+a)%t;
			}
		
		if(ans)
			printf("NO\n");
			else
			printf("YES\n");
	}
	return 0;
}
