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
struct tree t[(int)1e6];
struct lazy d[(int)1e6];
void setproperval(int i, int val) {
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
void updatenode(int i, int v, int start, int end) {
	setproperval(i, v);
	if(start != end) {
		d[i<<1].val   += v; 
		d[i<<1|1].val += v; 
	}
	d[i].val = 0;
} 
void update(int i, int start, int  end, int l, int r) {
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
int query(int i, int start, int end, int l, int r) {
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
	//cout << l <<  " " << r << endl;
	if(l > r) return;
//	cout << l << r << endl;
//	cout << l << " " << r << endl;  
	if(l == r) {
		t[i].zero = 1; 
		return;
	}
	int mid = (r+l)/2;
	build(i*2, l, mid);
	build(i*2+1, mid+1, r);
	t[i] = t[i<<1] + t[i<<1|1];
}
void print(int n) {
	for (int i = 1; i < 2*n; ++i)
		cout << i << " " << t[i].zero <<  " " << t[i].one << " " << t[i].two << endl;
}
void printd(int n) {
	for (int i = 1; i < 2*n; ++i)
		cout << i <<  " " << d[i].val << endl;
}
int main() {
	// your code goes here
	int n, q;
	si(n); si(q);
	int ch, l, r;
	build(1, 0, n-1); //cout << endl;
//	print(n);  cout << endl;
//	printd(n);
//	cout << 	query(1, 0, n-1, 0, n-1) << endl;
	while(q--) {
		si(ch);si(l); si(r);
		if(!ch) {
			update(1, 0, n-1, l, r);
		//	print(n);  cout << endl;
		//	printd(n);
		//	cout << l << " " << r << " " << query(1, 0, n-1, l, r) << endl;
		//	cout << query(1, 0, n-1, 0, n-1) << endl;
		}
		 else {
			cout << query(1, 0, n-1, l, r) << endl;
		 }
	}
	return 0;
}