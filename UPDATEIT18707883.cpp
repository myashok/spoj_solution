#include <iostream>
#include <cstring>
using namespace std;
int main() {
	long long te; cin >> te;
	while(te--) {
		long long n, u, l, r;
		long long val, temp = 0;
		scanf("%lld %lld", &n, &u);
		long long  arr[(long long)1e4+1]= {0}, t[(long long)1e4+1]={0};
		while(u--) {
			scanf("%lld %lld %lld", &l, &r, &val);
			t[l]   += val;
			t[r+1] -= val;
		}
		for (long long i = 0; i < n; ++i) {
			temp += t[i];
			arr[i] += temp;
		}
		long long q;
		scanf("%lld", &q);
		while(q--) {
			scanf("%lld", &l);
			printf("%lld\n", arr[l]);
		}
	}
	return 0;
}