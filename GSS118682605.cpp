#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int   sum, maxsum, lsum, rsum;
	node() {
		sum = maxsum = lsum = rsum = 0;
	}
};
typedef struct node node;
int  n;
node t[(int )1e7+2];
node calc(node left, node right) {
    node  res;
	res.sum    = left.sum + right.sum;
	res.lsum   = max(left.lsum, left.sum + right.lsum);
	res.rsum   = max(right.rsum, right.sum + left.rsum);
	res.maxsum = max( left.maxsum, max(right.maxsum, left.rsum + right.lsum));
	return res;
}
void build() {
	for(int  i = n-1; i > 0; --i) {
		t[i] = calc(t[i<<1], t[i<<1|1]);
	}
}
int  query(int  l, int  r) {
	node lres, rres;
	lres.sum = lres.lsum = lres.rsum = lres.maxsum = rres.sum = rres.lsum = rres.rsum = rres.maxsum = -1<<30;
	for(l += n, r += n; l < r; l >>=1 , r >>= 1){
		if(l&1) lres = calc(lres, t[l++]); 
		if(r&1) rres = calc(t[--r], rres);
	}
	return calc(lres, rres).maxsum;
}
int  main() {
	scanf("%d", &n);
	int  x;
	for (int  i = 0; i < n; ++i) {
		scanf("%d", &x);
		t[n+i].sum = t[n+i].lsum = t[n+i].rsum = t[n+i].maxsum = x;
	}
	build();
	int  m;
	scanf("%d", &m);
	int  l, r;
	while(m--) {
		scanf("%d %d", &l, &r);
		printf("%d\n",query(--l, r));
	}
	return 0;
}