#include <iostream>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
void f(int& x) {
	x = 0;
	register int c = gc();
	for (; (c < 48 || c > 57 ) && c != '-'; c = gc());
	bool neg = false;
	if(c == '-') {
		neg = true;
		c = gc();
	}
	for (; c >= 48 && c <= 57; c = gc()) {
		x = (x<<1) + (x << 3) + c - 48;  
	}
	if (neg) {
		x = -x;
	}
}
 
 
void p(int num){
    
    if (num < 0)
    {
       pc('-');
       num = -num;
    }
	if(num == 0) {
	//	cout << "mata";
		pc('0');
	//	pc('\n');
		return;
	}
	char buff[20];
	buff[19] = '\n';
	int i = 18;
	while(num) {
		buff[i--] = num%10+'0';
		num /= 10;
	}
	i++;
	while (buff[i] != '\n') {
		pc(buff[i]);
		i++;
	}
 }
int main() {
//	std::ios::sync_with_stdio(false);
	int n, t;
	f(n);
	int a[1000001]={0};
	while (n--) {
	
		f(t);
		a[t]++;
	}
	for(int i = 0; i <= 1000000; ++i) {
		while(a[i] > 0)  {
			p(i);
			pc('\n');
			a[i]--;
		}
	}
	
	return 0;
}
  