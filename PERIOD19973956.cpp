#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int te = 1;
	int cs; cin >> cs;
	while (cs--) {
		int n; cin >> n;
		string s;
		cin >> s;
		int f[s.length()];
		int i(1), j(0);
		f[0] = 0;
		while (i < n) {
			if(s[i] == s[j]) {
				f[i] = j + 1;
				i++;
				j++;
			}
			else if(j > 0) {
				j = f[j-1];
			}
			else  {
				f[i] = 0;
				i++;
			}
		}
		cout << "Test case #" << te++ << endl;
		for (int i = 2; i <= n; ++i) {
		 	int t = i - (f[i-1]);
		 	int ans = 1;
		// 	cout << t << " " << f[i-1] << " " << i << endl;
		 	if(i%t == 0 and f[i-1] >= (i-f[i-1]))
		 		ans = i/t;
		 	if(ans > 1) 
		 	cout << i << " " << ans << endl;
		}
	}
	return 0;
}