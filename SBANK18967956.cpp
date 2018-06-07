#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string s;
	map<string, int> mymap;
	while(t--) {
		int n;
		cin >> n;
	//	cout << n << endl;
		getline(cin, s);
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			mymap[s]++;
		}
		for (auto it = mymap.begin(); it != mymap.end(); ++it) {
			cout << it->first << " " << it->second << endl;
		}
		cout << endl;
		mymap.clear();
	}
	return 0;
}