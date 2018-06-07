#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int added = 0;
ll total = 0,  rsum[(int)1e5+1];
ll query(int i) {
	i = added - i;
	return (total - rsum[i]);
}
int main() {
	// your code goes her
	int n;
	cin >> n;
	ll arr[n+1], sum[n+1];
	rsum[0] = 0;
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
			rsum[added + 1] = val + rsum[added];
			added++;
			total += val; 
		}
	}
	return 0;
}