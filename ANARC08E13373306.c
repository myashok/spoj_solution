#include <stdio.h>

int main(void) {
    int a, b, t = 1, sum, up, down,ans,i;
	while ( ++t) {
		up = 1, down = 1;
	    scanf ( "%d %d", &a, &b);
		if (a == -1 && b == -1)
			break;
		sum = a+b;
		for(i = sum; i > a; --i)
			up = up*i;
			
		for (i = 1; i <= b; ++i )
			down = down*i;
		ans = up / down; 
		if (ans == sum){
			printf("%d+%d=%d\n",a,b,sum);
		}
		else printf("%d+%d!=%d\n",a,b,sum);
	}
	// your code goes here
	return 0;
}
