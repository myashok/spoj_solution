#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
using namespace std;

int main() {
	// your code goes here
	int t;
	si(t);
	int l, k;
	int n, sqn;
	while(t--) {
		si(l);si(k);
		priority_queue<int, vector<int>> Q;
		int sum = (l*(l+1))/2;
		for (int i = 1; i <= l; ++i) 
			Q.push(i);
		for (int i = 0; i < k; ++i) {
			 n = Q.top(); Q.pop();
			 sum -= n;
			 sqn = sqrt(n);
			 sum += sqn;
			 Q.push(sqn);
		}
		cout << sum << endl;
	}
	return 0;
}