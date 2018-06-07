#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int l, int mid, int h) {
	int n1 = (mid-l+1);
	int n2 = (h-mid);
	int L[n1], R[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = arr[i+l];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[mid+1+i];
	int i , j, k;
	i = j = 0;
	k = l;
	int ans = 0;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			ans = ans + (mid - (i+l) + 1);
			arr[k++] = R[j++];
			
		}
	}
	while(i < n1) {
		arr[k++] = L[i++];
	}
	while(j < n2) {
		arr[k++] = R[j++];
	}
	return ans;
}
int mergesort(int arr[], int l, int h) {
	if(l >= h) return 0;
	int mid = (l + h)/2;
	int left = mergesort(arr, l, mid);
	int right = mergesort(arr, mid+1, h);
	return left + right + merge(arr, l, mid, h);
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	string s;
	unordered_map<string, int> m;
	int arr[30000];
	while(t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			m[s] = i;
		}	
		for (int i = 0; i < n; ++i) {
			cin >> s;
			arr[m[s]] = i;
		}
		// for (int i = 0; i < n; ++i) {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;
		cout << mergesort(arr, 0, n-1) << endl; 
	}
	return 0;
}