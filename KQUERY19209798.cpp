#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
using namespace std;
int BIT[30001];
int n;
void update(int i) {
	for (; i <= n; i += i & -i)
		BIT[i] += 1;
}
int queryBIT(int i) {
	int ans = 0;
	for ( ;i > 0; i -= i & -i)
		ans += BIT[i];
	return ans;
}
struct arra {
	int val,  pos;
};
struct query {
	int i, j, k, pos;
};
inline bool arrcmp(const arra a, const arra b) {
	return a.val == b.val ? a.pos < b. pos : a.val > b.val;
}
inline bool querycmp(const  query a, const  query b) {
	return a.k == b.k ? a.i < b.i : a.k > b.k;
}
int main() {
	// your code goes here
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	si(n);
	arra arr[n+1];
	for (int i = 1; i <= n; ++i) {
		si(arr[i].val);
		arr[i].pos = i;
	}
	sort(arr+1, arr+n+1, arrcmp);
	// for (int i = 1; i <= n; ++i) {
	// 	cout << arr[i].val<< " ";
	// }
	// cout << endl;
	int q; si(q);
	struct query  Q[q+1];
	for (int i = 1; i <= q; ++i) {
		si(Q[i].i); si(Q[i].j); si(Q[i].k);
		Q[i].pos = i;
	}
	sort(Q+1, Q+q+1, querycmp);
	// for (int i = 1; i <= q; ++i) {
	// 	cout << Q[i].k <<  " " << Q[i].i << " " << Q[i].j << endl;
	// }
	int result[q+2], pos = 1;
	for (int i = 1; i <= q; ++i) {
		while(pos <= n && arr[pos].val > Q[i].k) {
			update(arr[pos].pos);
			pos++;
		}
	//	cout << /*Q[i].pos <<  " " <<*/ Q[i].k << endl;
		result[Q[i].pos] = queryBIT(Q[i].j) - queryBIT(Q[i].i - 1);
	}
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", result[i]);
	}
	return 0;
}