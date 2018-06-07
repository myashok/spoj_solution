#include <iostream>
using namespace std;
bool d[3*(int)1e5+1];
int t[3*(int)1e5+1] ;
inline void updateNode(int i, int start , int end){
 t[i] = (end-start+1) - t[i];
 if(start != end) {
 	d[i<<1] = !d[i<<1];
 	d[i<<1|1] = !d[i<<1|1];
 }
 d[i] = false;
}
int query(int i, int start, int end, int l, int r){
	if(d[i]) updateNode(i, start, end);
	if (start > end || l > end || start > r) 
		return 0;
	if(l <= start and end <= r) {
		return t[i];
	}
	int mid = (start + end)/2;
	return query(i<<1, start, mid, l, r) + query(i<<1|1, mid+1, end, l, r);
}
void update(int i, int start, int end, int l, int r){
	if(d[i]) updateNode(i, start, end);
	if (start > end || l > end || start > r) 
		return;
	if(l <= start and end <= r) {
		updateNode(i, start, end);
		return;
	}
	int mid = (start + end)/2;
	update(i<<1, start, mid, l, r);
	update(i<<1|1, mid+1, end, l, r);
	t[i] = t[i<<1] + t[i<<1|1];
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int ch, l, r;
	while(q--) {
		cin >> ch >> l >> r;
		if(ch) {
			cout << query(1, 0, n-1, --l, --r) << endl;
		}
		else {
			update(1, 0, n-1, --l, --r);
		}
	}
	return 0;
}