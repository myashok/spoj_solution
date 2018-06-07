#include <bits/stdc++.h>
using namespace std;
long long merge(int arr[], int l, int mid, int h) {
 int n1 = mid - l + 1, n2 = h-mid;
 int L[n1];
 int R[n2];
 for(int i = 0; i < n1; ++i) {
 	L[i] = arr[i+l];
 	// cout << L[i] <<  " ";
 }
 //cout <<  "  ";
 for(int i = 0; i < n2; ++i) {
 	R[i] = arr[i+mid+1];
 	// cout << R[i] << " ";
 }
 //cout << endl;
 long long count = 0;
 int i, j, k;
 i = j = 0;
 k = l;
 while(i < n1 && j < n2) {
 	if(L[i] <= R[j]) {
 		arr[k++] = L[i++];
 	}
 	else {
 		arr[k++] = R[j++];
 		count = count + (mid - (i+l) + 1);
 		// cout << (mid - (i+l) + 1) << endl;
 		// for (int it = i; it <= (mid); ++it)
 		// 	cout << R[j-1] <<  " " << arr[it] << endl;
 		//  cout << endl;
 	}
 }

 while(i < n1)
 	arr[k++] = L[i++];
 while(j < n2)
 	arr[k++] = R[j++];
 return count;
}
long long count(int arr[], int l, int h) {
	if(l >= h)
		return 0;
	int mid = (h-l)/2 + l;
	long long lcount = count(arr, l, mid);
	long long rcount = count(arr, mid+1, h);
	return merge(arr, l, mid, h) + lcount + rcount;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << count(arr, 0, n-1) << endl;
		// for (int i = 0; i < n; ++i)
		// 	cout <<  arr[i] << " ";
		// cout << endl;
	}
	return 0;
}