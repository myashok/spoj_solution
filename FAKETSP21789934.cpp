#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	double px=-1, py=-1;
	double dis = 0;
	while(getline(cin, s)) {
	   //double x, y;
	   string sx, sy;
	   int n = s.length();
	   int i = n-2;
	   for (; i >=0; --i) {
	      if (s[i] == ' ') {
	      	i--;
	      	break;
	      }
	      sy.push_back(s[i]);
	   }
	   for (; i >=0; --i) {
	      if (s[i] == '(') {
	         break;
	      }
	      sx.push_back(s[i]);
	   }
	   reverse(sy.begin(), sy.end());
	   reverse(sx.begin(), sx.end());
	   double x = stod(sx);
	   double y = stod(sy);
	   if(px != -1 and py != -1) {
	      //cout << x << " " << y << " " << px << " " << py << endl;
	      dis += sqrt((x-px)*(x-px) + (y-py)*(y-py));
	      //cout << dis << endl;
	      
	      printf("The salesman has traveled a total of %.3lf kilometers.\n", dis);
	   }
	   px = x; py = y;
	}
	return 0;
}