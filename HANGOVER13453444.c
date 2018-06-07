#include <stdio.h>

int main(void) {
	// your code goes here
	float a, b, c, d, e=1, i;
	int j;
	while (++e) {
		d = 0;
		scanf("%f", &a);
		if (a == 0) break;
		for (i = 2; i >= 1; ++i) {
			d = d + 1/i;
			if(a <= d)
			break;
		}
		j = i;
		printf("%d card(s)\n", j-1);
	}
	
	return 0;
}
