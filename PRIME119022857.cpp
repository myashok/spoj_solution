// Author - Saurabh

// SEGMENTED SIEVE 
/* Steps
1- find all the primes up to sqrt(b), call them primes[]
2- create a boolean array is_prime[] with length = b-a+1 and fill it with true
3- for each p in primes set is_prime[i*p - a] = false starting at i=ceil(a/p)
4- for each is_prime[i]=true print i+a
*/ 

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ll long long int
#define all a.begin(),a.end()
#define mod 1000000007
#define for0(i,a,n) for(int i=a;i<n;i++)
#define for1(i,a,n) for(int i=a;i<=n;i++)
#define N 40000
// N sqrt(1000000000)
bool primes[N],Prange[100001];
vector<int> prime;
unordered_set<int> NP;

void func()
{
	primes[1]=false;
	primes[0]=false;

	for(int i=2;i<=N;i++){
		if(primes[i]){
			for(int j=2*i;j<=N;j=j+i) primes[j]=false;
		}
	}

	for (int i = 2; i <=N; ++i)
		if(primes[i]) prime.pb(i);
}

int main(int argc, char const *argv[])
{
	memset(primes,true,sizeof(primes));
	func();
	//for(int i=0;i<prime.size();i++) cout<<prime[i]<<" "; cout<<endl;
	int n; scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		// a b are range
		
		NP.insert(1);
		for(int i=0;i<prime.size();++i){
 			int x = max(a/prime[i],2);
			//cout<<"x: "<<x<<endl;
			for(int j=x*prime[i];j<=b;j+=prime[i]) NP.insert(j);
		}
		// NP contains all the number which are not prime in range a to b
		// and traverse from  a to b and if number not found in NP THAN it is PRIME
		
		for(int i=a;i<=b;i++) if(NP.find(i) == NP.end()) printf("%d\n", i);
        printf("\n");
	}
	return 0;
}