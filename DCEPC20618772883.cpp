#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(ll arr[] ,ll l, ll mid, ll r) {
	ll n1 = mid - l + 1;
	ll n2 = r-mid;
	ll L[n1], R[n2];
	for (ll i = 0; i < n1; ++i)
		L[i] = arr[l+i];
	for (ll i = 0; i < n2; ++i)
		R[i] = arr[mid+1+i];
	ll sum = 0;
	ll i = 0, j = 0, k = l;
	// for(ll i = 0; i < n1; ++i)
	// 	 cout << L[i] << " ";
 //   cout << endl;
	// for(ll i = 0; i < n2; ++i)
	// 	 cout << R[i] << " ";
 //   cout << endl;
	while(i < n1 && j < n2) {
		if(L[i] < R[j]) {
		//	cout << i << " " << j << " " << r << " " << L[i] << endl; 
			sum += (r-(mid+1+j)+1)*L[i];
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	while(i < n1)
		arr[k++] = L[i++];
	while(j < n2)
		arr[k++] = R[j++];
	return sum;
}
ll mergesort(ll arr[], ll l, ll r) {
	if(l >= r)
		return 0LL;
	ll mid = (r-l)/2 + l;
	ll left = mergesort(arr, l, mid);
	ll right = mergesort(arr, mid+1, r);
	return left + right + merge(arr, l, mid, r);
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll arr[n];
		for (ll i = 0; i < n; ++i)
			cin >> arr[i];
		cout << mergesort(arr , 0, n-1) << endl;
	}
	return 0;
}