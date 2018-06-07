#include <stdio.h>
#define TAX 1000000
int main(void) {
	int i, j, k, n,ng[TAX], nm[TAX],max,max2,l;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &j, &k);
		for (l = 0; l < j; ++l)
			scanf("%d", &ng[l]);
		for (l = 0; l < k; ++l)
			scanf("%d", &nm[l]);
		max = ng[0];
		for (l = 0; l < j; ++l)
			if(ng[l] > max)
				max = ng[l];
        max2 = nm[0];
		for (l = 0; l < k; ++l)
			if(nm[l] > max2)
				max2 = nm[l];
		if(max < max2)
			printf("MechaGodzilla\n");
			else
			printf("Godzilla\n");
		}
	return 0;
}
