#include <stdio.h>

int main(void) {
	// your code goes here
 long int n, i, j , k, t=1;
 while(t++) {
 	scanf("%ld%ld%ld", &i, &j, &k);
 	if((i==0 && j == 0) && k == 0)
 		break; 
 	if((i+k)==(2*j))
 		printf("AP %ld\n", k+(j-i));
 	else 
 		printf("GP %ld\n", k*(j/i));
 }
	return 0;
}
