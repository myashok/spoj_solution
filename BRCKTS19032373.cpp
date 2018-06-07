#include <bits/stdc++.h>
using namespace std;
struct tree {
	int open, close;
	tree() {
		open = close = 0;
	}
};
int n;
struct tree t[60000+1];
struct tree mymerge(struct tree l, struct tree r) {
	struct tree temp; 
	int matched = min(l.open, r.close);
	temp.open = l.open + r.open - matched; 
	temp.close = l.close + r.close - matched;
	return temp;
}
bool check(int l, int r) {
  struct tree resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = mymerge(resl, t[l++]);
    if (r&1) resr = mymerge(t[--r], resr);
  }
  return mymerge(resl, resr).open == 0 && mymerge(resl, resr).close == 0;
}
void merge(int i) {
	int matched = min(t[i<<1].open, t[i<<1|1].close);
	t[i].open = t[i<<1].open + t[i<<1|1].open - matched; 
	t[i].close = t[i<<1].close + t[i<<1|1].close - matched; 
}
void build() {
	for (int i = n-1; i > 0; --i) {
		merge(i);
	}
}
void modify(int i) {
	i = i+n;
//	cout << i + n << endl;
	t[i].open = t[i].open^1;
	t[i].close = t[i].close^1;
	for ( ; i >>= 1;) {
		int matched = min(t[i<<1].open, t[i<<1|1].close);
		t[i].open = t[i<<1].open + t[i<<1|1].open - matched; 
		t[i].close = t[i<<1].close + t[i<<1|1].close - matched; 
	}
}
void print() {
	for (int i = 1; i < 2*n; ++i) {
		cout << i << " " << t[i].open << " " << t[i].close <<  endl;
	}
}
int main() {
	// your code goes here
	int te = 10;
	int cnt = 1;
	while(te--) {
		cin >> n;
		string str;
		printf("Test %d:\n", cnt++);
		cin >> str;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '(') {
			//	cout << "open" << " " <<  (n+i) << endl;
				t[n+i].open = 1;
				t[n+i].close = 0;
			}
			else {
			//	cout << "close" << " " <<  (n+i) << endl;
				t[n+i].open = 0;
				t[n+i].close = 1;
			}
		}
		build();
	//	print();
		int q;cin >> q;
		int x;
		while(q--) {
			cin >> x;
		//	print();
			if(x) {
				modify(x-1);
				
			}
			else {
				if(check(0, n)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}