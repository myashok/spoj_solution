#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string findpal(string s) {
	string rs = s;
	reverse(rs.begin(), rs.end());
	string t = rs + "$" + s;
	int f[t.size()] = {0};
	int i(1), j(0);
	int n = t.size();
	while (i < n) {
		if(t[i] == t[j]) {
			f[i] = j + 1;
			i++, j++;
		}
		else if(j > 0) {
			j = f[j-1];
		}
		else {
			f[i] = 0;
			i++;
		}
	}
	int len = f[n-1];
	return s + rs.substr(len);
}
int main() {
	// your code goes here
	string s;
	while (cin >> s) {
		cout << findpal(s) << endl;
	}
	return 0;
}