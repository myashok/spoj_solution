#include <stdio.h>

int main(void) {
	long int n, i, t = 1,count=0;
	char str[10000];
	scanf("%s",str);
	for (i = 0; str[i] != '\0'; ++i) {
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		count++;
	}
	printf("%ld",count);
	return 0;
}

