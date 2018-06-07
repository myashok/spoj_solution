#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#define f(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
using namespace std;
int isPrime(int n){
    int i;
 
    if (n==2)
        return 1;
 
    if (n%2==0)
        return 0;
	int l = sqrt(n);
    for (i=3;i<=l;i+=2)
        if (n%i==0)
            return 0;
    return 1;
}
void simple_seive(vector<int> &prime, int n) {
	vector<bool> mark(n+1, true);
	prime.push_back(2);
	for (int i = 3; i * i <= n; i += 2) {
		if (mark[i/2]) {
			for (int index = i*i; index <= n; index+=i*2) 
				mark[index/2] = false;
		}
	}
	for (int i = 1; i < n/2; ++i) {
		if(mark[i]) 
			prime.push_back(i*2+1);
	}
//	cout << prime[prime.size()-1] << endl;
/*	for (int i = 0; i < prime.size(); ++i) {
	     cout << prime[i] << " ";
	}*/
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	int t, m, n;
	cin >> t;
	vector<int> prime;
	int n1 = 31650;
	simple_seive(prime, n1);
	while (t--) {
		cin >> m >> n;
		assert(1<=(n-m) && (n-m) <= 100000);
		assert(n<=1000000000 && 1 <= n);
		assert(m<=1000000000 && 1 <= m);
		if(n <= n1) {
			int size = prime.size();
			int i;
			for (i = 0; i < size; ++i) {
				if(prime[i] >= m)
					break;
			}
			for (int j = i; j < size; ++j) {
				if (prime[j] > n)
					break;
				cout << prime[j] << endl;
			}
		}
		else {
		 	vector<bool> mark(n-m+1, true);
			int low  = m;
			int high = n; 
		//	cout << (n-m) << endl;
		//	for (int i = 0; i <= n-m; i++) 
		//		cout << mark.at(i) << " " << (m+i) << endl;
			for (int i = 0; i < prime.size(); i++) {
        		int loLim = floor(low/prime[i]) * prime[i];
        	//	cout << loLim << endl;
           		if (loLim < low)
               		loLim += prime[i];
               	if (loLim == prime[i])
               		loLim += prime[i];
              // 	cout << loLim << endl;
            	for (int j=loLim; j<=high; j+=prime[i])
                	mark[j-low] = false;
    		}
    	//	for (int i = 0; i <= n-m; i++) 
		//		cout << mark.at(i) << " " << (m+i) << endl;
			int i;
			m == 1 ? i = m+1:i = m;
    		for (; i<=n; i++)
            	if (mark[i - low] == true)
               		cout << i << endl;
			}
			
		}
	
	return 0;
} 