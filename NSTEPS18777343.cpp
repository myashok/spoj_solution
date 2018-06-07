#include <bits/stdc++.h>
#define si(x) scanf("%lld", &x);
using namespace std;

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--) {
		int x, y;
		si(x); si(y);
		if(x == y) {
			if(x&1) {
				x++;
				printf("%d\n",x*2-3);
			}
			else 
				printf("%d\n",x*2);
				
		}
		else if(x-2 == y) {
			if(x&1) {
				x++;
				printf("%d\n",x*2-5);
			}
			else {
				printf("%d\n", x*2-2);
			}
		}
		else {
			printf("No Number\n");
		}
	}
	return 0;
}