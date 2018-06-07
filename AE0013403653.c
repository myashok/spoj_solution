#include <stdio.h>
#include <math.h>
int main(void) {
  long long int n, i,j ,count = 0;
  scanf("%lld", &n);
  for(i = 1; i <= n; ++i) {
  	int no = sqrt(i);
  	for (j = 1;j <= no; ++j) {
  		if(i%j==0)
  		count++;
  	}
  }
printf("%lld",count);
return 0;
}


