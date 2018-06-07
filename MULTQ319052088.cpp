#include <bits/stdc++.h>
#define si(x) scanf("%d", &x);
using namespace std;
struct tree {
	int zero, one, two;
	tree() {
		 one = two = zero = 0;
	}
	tree operator+(const struct tree & b) {
		struct tree t;
		t.zero = this->zero + b.zero;
		t.one  = this->one + b.one;
		t.two  = this->two + b.two;
		return t;
	}
};
struct lazy {
	int val;
	lazy() {
		val = 0;
	}
};
struct tree t[(int)3e5];
struct lazy d[(int)3e5];
inline void setproperval(int i, int val) {
	val %= 3;
	if(val == 1) {
		int x = t[i].zero, y = t[i].one, z = t[i].two;
		t[i].zero = y;
		t[i].one = z;
		t[i].two = x;
	}
	else if(val == 2) {
		int x = t[i].zero, y = t[i].one, z = t[i].two;
		t[i].zero = z;
		t[i].one = x;
		t[i].two = y;
	}
}
inline void updatenode(int i, int v, int start, int end) {
	setproperval(i, v);
	if(start != end) {
		d[i<<1].val   += v; 
		d[i<<1|1].val += v; 
	}
	d[i].val = 0;
} 
inline void update(int i, int start, int  end, int l, int r) {
	if(d[i].val) 
		updatenode(i, d[i].val, start, end);
	if(start > end || r < start || l > end)
		return;
	else if(l <= start && end <= r) {
		 updatenode(i, 1, start, end);
		 return;
	}
	int mid = (end - start) / 2 + start;
	update(i<<1, start, mid, l, r);
	update(i<<1|1, mid+1, end, l, r);
	t[i] = t[i<<1] + t[i<<1|1];
}
inline int query(int i, int start, int end, int l, int r) {
	if(d[i].val) 
		updatenode(i, d[i].val, start, end);
	if(start > end || r < start || l > end)
		return 0;
	else if(l <= start && end <= r)
		return t[i].zero;
	int mid = (end - start) / 2 + start;
	return query(i<<1, start, mid, l, r) + query(i<<1|1, mid+1, end, l, r);
}
void build(int i, int l, int r) {
	if(l > r) return;
	if(l == r) {
		t[i].zero = 1; 
		return;
	}
	int mid = (r+l)/2;
	build(i*2, l, mid);
	build(i*2+1, mid+1, r);
	t[i] = t[i<<1] + t[i<<1|1];
}
int main() {
	int n, q;
	si(n); si(q);
	int ch, l, r;
	build(1, 0, n-1);
	while(q--) {
		si(ch);si(l); si(r);
		if(!ch) {
			update(1, 0, n-1, l, r);
		
		}
		 else {
			printf("%d\n",query(1, 0, n-1, l, r));
		 }
	}
	return 0;
}