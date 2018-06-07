#include <bits/stdc++.h>
using namespace std;
int n;
int BIT[(int)1e6+4];
inline void update(int i, int val) {
	for ( ; i <= n; i += i & -i)
		BIT[i] += val;
}
inline int query(int i) {
	int sum = 0;
	for ( ; i > 0; i -= i & -i)
		sum += BIT[i];
	return sum;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int q, u, v;
	cin >> n >> q;
	string str;
	while(q--) {
		cin >> str >> u >> v;
		if(str == "add") {
			update(u, v);
		}
		else {
			cout << (query(v) - query(u-1)) << endl;
		}
	}
	return 0;
}