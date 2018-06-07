#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	int n, i, l, j;
	scanf("%d", &n);
	char arr[11];
	for (i = 0; i < n; ++i) {
		scanf("%s",arr);
		l = strlen(arr);
		for(j = 0; j < l/2; ++j) {
			if(arr[j] != arr[l-j-1])
			break;
		}
		if(j == l/2)
			printf("YES\n");
		else printf("NO\n");
		
		}
	return 0;
}
	