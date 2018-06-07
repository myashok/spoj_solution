#include <stdio.h>
#include <string.h>
int main(void) {
	int n, i, j, k, t, row,len ,l;
	char a[100000];
	while (++t) {
		scanf("%d", &t);
		if (t==0)break;
		scanf("%s",a);
		len = strlen(a);
		row = len/t;
		for(i = 0; i < t ;++i) {
			for (j =0 ; j < row; ++j) {
				if(j % 2 == 0)  {
					k = t*j+i;
				printf("%c",a[k]);
				}
				else{
				k = t*j+(t-i);
				printf("%c",a[k-1]);}
			}
		}
	printf("\n");
	}
	
	return 0;
}
