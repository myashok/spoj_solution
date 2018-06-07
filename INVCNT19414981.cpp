#include<bits/stdc++.h>
using namespace std;
long long merge(long long arr[], long long l, long long mid, long long h) {
    long long n1 = mid - l + 1;
    long long n2 = h - mid;
    long long L[n1]; long long R[n2];
    for (long long i = 0; i < n1 ; ++i)
        L[i] = arr[l+i];
    for (long long i = 0; i < n2; ++i)
        R[i] = arr[mid+1+i];
    long long i, j, k;
    i = 0, j = 0, k = l;
    long long count = 0;
    while( i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++]; 
        }
        else {
            count = count + (n1 - i);
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
    return count;
}
long long count(long long arr[], long long l, long long h) {
    if(l < h) {
        long long mid = (l+h)/2;
        long long left = count(arr, l, mid);
        long long right = count(arr, mid+1, h);
      //  cout << "left " << left << "right " << right << endl;
        return merge(arr, l, mid, h) + left + right;
    }
    return 0;
}
int main()
{
	//code
	long long t; cin >> t;
	while(t--) {
	    long long n; cin >> n;
	    long long arr[n];
	    for (long long i = 0; i < n; ++i) 
	        cin >> arr[i];
	   cout << count(arr, 0, n-1) << endl;
	   // for (long long i = 0; i < n; ++i) 
	   //     cout <<  arr[i];
	}
	return 0;
}