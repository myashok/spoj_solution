#include <stdio.h>
int main() {
	long int a, t=0, sum = 0, d;
	scanf("%ld",& a);
	while(++t) {
		while (a > 0) {
			d = a%10;
			sum = sum + d*d;
			a = a/10;
			}
		a = sum;
		sum = 0;
		if (a==1) {
			printf("%d\n",t);
			break;
		}
		if(t==500) {
			printf("-1\n");
			break;
		}
		
	}
	return 0;
}