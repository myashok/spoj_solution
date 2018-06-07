#include <iostream>
#include <cstring>
using namespace std;
#define si(x) scanf("%d", &x)
int T[(int)1e4+2];
int n, u, q;
int main() {
	int t, l, r, val;
	si(t);
	while(t--) {
		memset(T, 0, sizeof(T));
		si(n);
		si(u);
		while(u--) {
			si(l);si(r);si(val);
			T[l] += val;
			T[r+1] -= val;
		}
		for(int i = 1; i < n; ++i)
			T[i] += T[i-1];
		si(q);
		while(q--) {
			si(l);
			printf("%d\n", T[l]);
		}
	}
	return 0;
}