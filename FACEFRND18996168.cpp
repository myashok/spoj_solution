#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	int temp;
	int size = t;
	vector<vector<int> > data;
	map<int, bool> frnd;
	while(t--) {
		int n;
		cin >> temp >> n;
		frnd[temp] = true;
		vector<int> tmp(n);
		for (int i = 0; i < n; ++i) {
			cin >> tmp[i];
		}
		data.push_back(tmp);
	}
	int ans = 0;
//	cout << size << endl;
	map<int, bool> mark;
	for (int i = 0; i < size; ++i) {
		int count = data[i].size();
		for (int j = 0; j < count; ++j)  {
			if(frnd[data[i][j]] == false && !mark[data[i][j]])	
				ans++;
			mark[data[i][j]] = true;
		}
	//	cout << endl;
	}
	cout << ans << endl;
	return 0;
}