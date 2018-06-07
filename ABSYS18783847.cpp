#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str[3], temp;
		for(int i = 0, k = 0; i < 5; ++i) {
			if(i == 1 || i == 3) {cin >> temp; continue;}
			cin >> str[k++];
		}
		int a[3], index;
		for (int i = 0, k = 0; i < 3; ++i) { 
			//cout << str[i] << endl;
		 	if(str[i].find("machula") != string::npos) {
		 		index = i;
		 		continue;
		 	}
		 	a[i] = stoi(str[i]);	
		 //	cout << a[i] << " ";
		}
	//	cout << endl;
		if(index == 0 || index == 1){
			a[index] = a[2] - a[index^1]; 
		}
		else {
			a[index] = a[1] + a[0];
		}
		printf("%d + %d = %d\n",a[0], a[1], a[2]);
	}
	return 0;
}