#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[(ll)2e6+1], d[(ll)2e6+1];
int n, h;
void updateNode(ll i, ll v, ll start, ll end) {
	t[i] += (end-start+1)*v;
	if(start != end) {
		d[i<<1] +=v ; d[i<<1|1] += v;
	}
	d[i] = 0;
}
void update(ll i, ll start, ll end, ll l, ll r, ll v) {
	if(d[i]) 
		updateNode(i, d[i], start, end);
	if(start > end || start > r || end < l)
		return;
	else if(l <= start and end <= r) {
		updateNode(i, v, start, end); 
		return;
	}
	ll mid = (end-start)/2 + start;
	update(i<<1, start, mid, l, r, v);
	update(i<<1|1, mid+1, end, l, r, v);
	t[i] = t[i<<1]+t[i<<1|1];
		 
}
ll query(ll i, ll start, ll end, ll l, ll r){
	if(d[i])
		updateNode(i, d[i], start, end);
	if(start > end || start > r || end < l)
		return 0L;
	else if(l<= start and end <= r) 
		return t[i];
	ll mid = (end-start)/2 + start;
	return query(i<<1,start, mid, l, r) + query(i<<1|1, mid+1, end, l, r);
	
}
int main() {
	ll te, m, ch, l, r, v;
	cin >> te;
	while(te--) {
		cin >> n >> m;
		memset(t, 0, sizeof(t));
		memset(d, 0, sizeof(d));
		while(m--) {
			cin >> ch;
			if(!ch) {
				cin >> l >> r >> v;
				update(1, 0, n-1, --l, --r, v);
			}
			else {
				cin >> l >> r;
			//	cout << l <<  " " << r << endl;
				cout << query(1, 0, n-1, --l, --r) << endl;
			}
		}
	}
	return 0;
}