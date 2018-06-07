#include <stdio.h>

int main(void) {
	// your code goes here
	int i, j, k , l, n, a[1000000], t,key,m;
	long int count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		count = 0;
		scanf("%d", &l);
		for (m = 0; m < l; ++m) 
			scanf("%d", &a[m]);
		for (k = 1; k < l; ++k) {
			key = a[k];
			j = k - 1;
			while(j != -1 && a[j] > key) {
				a[j+1] = a[j];
				count++;
				j--;
			}
			a[j+1]  = key;
		}
		printf("%ld\n", count);
			}
	return 0;
}
