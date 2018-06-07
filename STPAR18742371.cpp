#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	// your code goes here
	int n, x;
	while(1) {
		cin >> n;
		if(n == 0)
		  return 0;
		queue<int> Q;
		stack<int> Side;
		vector<int> V;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			Q.push(x);
			V.pb(x);
		}
		sort(V.begin(), V.end());
		auto ptr = V.begin();
		while(!Q.empty()) {
			if(Q.front() == *ptr) {
				Q.pop();
				ptr++;
			}
			else if(!Side.empty() && Side.top() == *ptr) {
				Side.pop();
				ptr++;
			}
			else {
				Side.push(Q.front());
				Q.pop();
			}
		}
		bool flag = true;
		while(!Side.empty()) {
			if(Side.top() == *ptr) {
				Side.pop();
				ptr++;
			}
			else {
				cout << "no\n";
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "yes\n";
	}
	return 0;
}