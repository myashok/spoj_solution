#include <bits/stdc++.h>
using namespace std;
#define pb push_back
inline long long solve(long long n) {
 if(n == 1) return 0;
 long long result = 1;
 long long root = sqrt(n);
 for (long long i = 2; i <= root; ++i) {
 	if(n%i == 0) {
 		if(i == (n/i))
 		 result += i;
 		else 
 		 result += (i+n/i);
 	}
 }
 return result;
}
int main(void) {
	long long t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}