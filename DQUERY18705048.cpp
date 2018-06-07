#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct query{
	int l, r, id;
}q[(int)2e5+1];
int arr[(int)3e4+1], ct[(int)1e6+1];
int ans[(int)2e5+1];
int block_size, n, m, currans = 0;
inline bool mycomp(struct query x, struct query y){
    if (x.l/block_size != y.l/block_size)
        return x.l/block_size < y.l/block_size;
    return x.r < y.r;
}
inline void add(int no) {
	if(ct[no] == 0)
		currans++;
	ct[no]++;
}
inline void remove(int no) {
	ct[no]--;
	if(ct[no] == 0)
		currans--;
}
void mo() {
	int moLeft = 0, moRight = -1;
    int left, right;
	for(int i = 0; i < m; ++i) {
		left  = q[i].l;
		right = q[i].r;
		while(moRight < right) {
			add(arr[++moRight]);
		}
		while(moRight > right) {
			remove(arr[moRight--]);
		}
		while(moLeft < left) {
			remove(arr[moLeft++]);
		}
		while(moLeft > left ) {
			add(arr[--moLeft]);
		}
		ans[q[i].id] = currans;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	
		scanf("%d", &arr[i]);
    scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].l--; q[i].r--;
		q[i].id = i;
	}
	block_size = sqrt(n);
	sort(q, q+m, mycomp);
	mo();
	for(int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}