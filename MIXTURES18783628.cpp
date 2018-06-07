#include <bits/stdc++.h>
using namespace std;
int BIT[102];
int n;
void update(int i, int val) {
	for ( ;i <= n; i += i & -i) {
		BIT[i] += val;
	}
}
int query(int i) {
	int res = 0;
	for ( ;i > 0; i -= i & -i)
	 	res += BIT[i];
	 return res%100;
}
int main() {
	while(scanf("%d", &n) != EOF) {
		int arr[n+1];
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			update(i, arr[i]);
		}
		int m[n+1][n+1] = {0};
		for (int l = 2; l <= n; ++l) {
			for(int i = 1; i <= (n-l+1); ++i) {
				int j = i+l-1;
				m[i][j] = 1<<29;
				for(int k = i; k < j; ++k) {
					int q = m[i][k] + m[k+1][j] + ((query(k) - query(i-1)+100)%100)*((query(j) - query(k) + 100)%100);
					if(q < m[i][j]) {
						m[i][j] = q;
					}
				}
			}
		}
		cout << m[1][n] << endl;
	}
	return 0;
}