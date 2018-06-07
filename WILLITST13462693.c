#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	long long int n,count=0;
	scanf("%lld", &n);
	while (n > 1) {
  if  (n % 2 == 0)
    n = n/2;
  else
    n=3*n+3;
	if(count==1000000 || n >= 1000000000000000000)
		break;
	count++;
}	
	if(count==1000000 || n >= 1000000000000000000)
		printf("NIE\n");
	else
		printf("TAK\n");
	return 0;
}
