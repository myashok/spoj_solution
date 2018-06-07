#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	while (1) {
		string s;
		cin >> s;
		if(s == "*") break;
		int n = s.length();
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
		// for (int i = 0; i < n; ++i)
		// 	cout << f[i] << " ";
	 //	cout << endl;
	 	int t = n - (f[n-1]);
	//	cout << t << " " << f[n-1] << " " << n << endl;
	 	int ans = 1;
	 	if(n%t == 0 and f[n-1] >= (n-f[n-1]))
	 		ans = n/t;
	 	cout << ans << endl;
	}
	return 0;
}