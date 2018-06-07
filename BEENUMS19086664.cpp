#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	map<int, bool> mymap;
	int j = 0;
	for (int i = 1; i <= (int)1e9; j += 6 , i += j) {
		mymap[i] = true;
	} 
	int n;
	while(1) {
		scanf("%d", &n);
		if(n == -1) break;
		mymap[n] ? cout << "Y\n" : cout << "N\n";
	}
	return 0;
}