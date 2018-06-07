#include <bits/stdc++.h>
using namespace std;
struct node {
	int nr[2], p;	
}L[(int)1e6+1];
int P[20][(int)1e6+1], arr[(int)1e6+1];
int stp, cnt;
int n;
typedef struct node node;
bool mycomp(node a, node b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
void calculateSuffixArray(string s) {
	for (int i = 0; i < n; i++)
		P[0][i] = s[i] - 'a';
	for (stp = 1, cnt = 1; cnt >> 1 < n; stp ++, cnt <<= 1) {
		for (int i = 0; i < n; i ++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < n ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L, L + n, mycomp);
		for (int i = 0; i < n; i++)
		P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) ? P[stp][L[i - 1].p] : i;
	}
	int pos = ceil(log(n)/log(2));
    for(int i=0;i<n;i++)
        arr[P[pos][i]] = i;
}
int lcp(int x, int y) {
	int k, ret = 0;
	for (k = stp - 1; k >= 0 && x < n && y < n; k --)
		if (P[k][x] == P[k][y])
			(x += 1 << k), (y += 1 << k),(ret += 1 << k);
	return ret;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string s;
	while(t--) {
		cin >> s;
		n = s.length();
		calculateSuffixArray(s);
		// for(int i = 0; i < n; ++i)
		// 	cout << arr[i] << endl;
		int ans = (n*(n+1))/2;
		for(int i = 1 ; i < n; ++i) {
			ans -= lcp(arr[i], arr[i-1]);	
		}
		cout << ans << endl;
	}
	return 0;
}