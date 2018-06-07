#include <bits/stdc++.h>
using namespace std;
struct node{
	int lcount, rcount;
	struct node *lchild, *rchild;
	node() {
		lcount = rcount = 0;
		lchild = rchild = nullptr;
	}
};
typedef struct node node; 
node *root;
void addNo(int n) {
	node *troot = root;
	for(int i = 25; i >= 0; --i) {
		int bit = (n>>i) & 1;
		if(bit) {
			troot->rcount++;
			if(troot->rchild == nullptr)
				troot->rchild = new node();
			troot = troot->rchild;
		}
		else {
			troot->lcount++;
			if(troot->lchild == nullptr)
				troot->lchild = new node();
			troot = troot->lchild;
		}
	}
}
int query(int n, int k) {
	node *troot = root;
	int res = 0;
	for(int i = 25; i >= 0; --i) {
		int nbit = (n>>i) & 1;
		int kbit = (k>>i) & 1;
		if(kbit) {
			if(nbit) {
				res += troot->rcount;
				if(troot->lchild == nullptr)
					return res;
				troot = troot->lchild;
			}
			else {
				res += troot->lcount;
				if(troot->rchild == nullptr)
					return res;
				troot = troot->rchild;
			}
		}
		else {
			if(nbit) {
				if(troot->rchild == nullptr)
					return res;
				troot = troot->rchild;
			}
			else {
				if(troot->lchild == nullptr)
					return res;
				troot = troot->lchild;
			}
		}
	}
	return res;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		root = new node();
		addNo(0);
		int prev = 0, curr;
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			cin >> curr;
			curr = prev^curr;
			ans += query(curr, k);
			addNo(curr);
			prev = curr;
		}
		cout << ans << endl;
	}
	return 0;
}