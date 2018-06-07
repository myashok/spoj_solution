#include <bits/stdc++.h>
using namespace std;
struct node {
	int a, b;
	int sum;
	node () {
		sum = a = b =0;
	}
};
node t[(int)3e5];
int arr[(int)1e5+1];
void setvalue(int i) {
	if(t[i<<1].a > t[i<<1|1].a) {
		t[i].a = t[i<<1].a;
		t[i].b = max(t[i<<1].b, t[i<<1|1].a);
		t[i].sum = t[i].a + t[i].b;
	}
	else {
		t[i].a = t[i<<1|1].a;
		t[i].b = max(t[i<<1|1].b, t[i<<1].a);
		t[i].sum = t[i].a + t[i].b;
	}
}
void build(int start, int end, int i){
	if(start == end) {
		t[i].a =  arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, i<<1);
	build(mid+1, end, i<<1|1);
	setvalue(i);
}
void update(int i, int start, int end, int index, int value) {
	if(index < start || index > end ) return;
	if(start == end) {
		t[i].a =  value;
		return;
	}
	else {
		int mid = (start + end)/2;
		update(i<<1, start, mid, index, value);
		update(i<<1|1, mid+1, end, index, value);
		setvalue(i);
	}
}
pair<int, int> query(int i, int start, int end, int l, int r) {
	if(l <= start && end <= r) 
		return make_pair(t[i].a, t[i].b);
	
	if(start > end || start > r || end < l) 
		return make_pair(0, 0);
	int mid = (start + end) / 2;
	auto left = query(i<<1, start, mid, l, r);
	auto right = query(i<<1|1, mid+1, end, l, r);
	if(left.first > right.first) {
		return make_pair(left.first, max(right.first, left.second));
	}
	else return make_pair(right.first, max(right.second, left.first));
}
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
//	int arr[n];
	for (int i = 0; i < n; ++i) cin >> arr[i];
	build(0, n-1, 1);
	int q, l, r; cin >> q;
	char ch;
	while(q--) {
		cin >> ch >> l >> r;
		if(ch == 'U') {
			update(1, 0, n-1, --l, r);
		}
		else {
			auto u = query(1, 0, n-1, --l, --r);
			cout << (u.first + u.second) << endl;
		}
	}
	return 0;
}