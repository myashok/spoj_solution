#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t[(int)2e5+4][2];
int n;
void build() {
	for(int i = n-1; i >= 1; --i) {
		t[i][0] = t[i<<1][0] <= t[i<<1|1][0] ? t[i<<1][0] : t[i<<1|1][0];
		t[i][1] = t[i<<1][0] <= t[i<<1|1][0] ? t[i<<1][1] : t[i<<1|1][1];
		
	}
}
pair<ll, ll> query(int l, int r) {
	ll res = INT_MAX, ind = -1, temp;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) {
			temp = t[l][0] < res ?	t[l][0]: res;
			ind  = t[l][0] < res ?	t[l][1]: ind;
			res  = temp;
			l++;
		}
		if(r&1) {
			--r;
			temp = t[r][0] < res ?	t[r][0]: res;
			ind  = t[r][0] < res ?	t[r][1]: ind;
			res = temp;
		}
	}
	return make_pair(res, ind);
}
ll solve(int l, int r) {
	if(l >= r)
		return 0;
	auto p = query(l, r);
//	cout << p.second << " " << p.first << endl;
	ll ans = p.first * (r-l);
	ll left = solve(l, p.second);
	ll right = solve(p.second+1, r);
	return ans = max(left, max(right, ans));
}
int main() {
	// your code goes here
	while(1) {
		scanf("%lld", &n);
		if(n == 0) return 0;
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &t[n+i]);
			t[n+i][1] = i; 
		}
		build();
		printf("%lld\n", solve(0, n));
	}
	return 0;
}