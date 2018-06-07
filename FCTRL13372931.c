#include <stdio.h>

int main(void) {
	long int  t, a, b, zeros;
	scanf ( "%ld",  &t );
	while ( t-- ) {
		zeros = 0;
		scanf ( "%ld", &a);
		b = 5;
		while  ( a >= b ) {
			zeros = zeros + (a/b);
			b*=5;
		}
	printf("%ld\n", zeros);
	}
	// your code goes here
	return 0;
}
