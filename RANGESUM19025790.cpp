#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int added = 0;
ll BIT[(int)1e5+1];
ll total = 0;
void update(int i, int val) {
	int n = (int)1e5+1;
	for ( ;i <= n; i += i & -i)
		BIT[i] += val;
}
ll query(int i) {
	int n = (int)1e5+1;
	i = added - i;
	ll sum = 0;
	for ( ;i > 0; i -= i & -i)
		sum += BIT[i];
	return (total - sum);
}
int main() {
	// your code goes her
	int n;
	cin >> n;
	ll arr[n+1], sum[n+1];
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i]; 
	}
	int q;
	cin >> q;
	int ch, l, r;
	ll val;
	while(q--) {
		cin >> ch;
		if(ch == 1) {
			cin >> l >> r;
			l--;
			ll lsum, rsum;
			lsum = rsum = 0;
			if(l <= added) {
				lsum = query(l); 
			}
			else {
				lsum = query(added);
				lsum += sum[l-added];
			}
			if(r <= added) {
				rsum = query(r); 
			}
			else {
				rsum = query(added);
				rsum += sum[r-added];
			}
			cout << (rsum - lsum) << endl;
		}
		else {
			cin >> val;
			update(++added, val);
			total += val;
		}
	}
	return 0;
}