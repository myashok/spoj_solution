#include <bits/stdc++.h>
using namespace std;
int arr[35];
int dd[35][35];
int ds[35][35];
int dumb(int i, int j) {
	if(i == j) {
		return dd[i][j] = arr[j];
	}
	if(i > j) return 0;
	int &res = dd[i][j];
	if (res != -1) return res;
	res = max(arr[i] + max(dumb(i+1, j-1), dumb(i+2, j)), arr[j] + max(dumb(i, j-2), dumb(i+1, j-1)));
	return res;
}
int smart(int i, int j) {
	if(i == j) {
		return ds[i][j] = arr[j];
	}
	if(i > j) return 0;
	int &res = ds[i][j];
	if (res != -1) return res;
	res = max(arr[i] + min(smart(i+1, j-1), smart(i+2, j)), arr[j] + min(smart(i, j-2), smart(i+1, j-1)));
	return res;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(dd, -1, sizeof(dd));
		memset(ds, -1, sizeof(ds));
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << dumb(0, n-1) << " " << smart(0, n-1) << endl;
	}
	return 0;
}