#include <stdio.h>

int main(void) {
	int i, j, n, t=1, a[1000000], count=0, sum;
	float k;
	while(t++) {
		scanf("%d", &n);
		sum = 0;
		count = 0;
		j = 0;
		if(n == -1)
		break;
		else {
			for (i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
				count++;
				sum = sum + a[i];
		}
		 k =(float) sum/count;
		 sum = sum/count;
		 //printf("%f\n", k - sum);
		 if(k-sum == 0) {
		 	for(i = 0; i < n; ++i) 
		 		if(sum > a[i])
		 		j = j + sum - a[i];
		 }
		 else
		 	printf("-1\n");
		 if (k-sum == 0)
		 	printf("%d\n", j);
		 
	}
	}
	return 0;
}
