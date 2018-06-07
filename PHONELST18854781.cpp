#include <bits/stdc++.h>
using namespace std;
struct node{
	struct node *child[10];
	bool end;
	node() {
		for(int i = 0; i <= 9; ++i)
			child[i] = nullptr;
		end = false;
	}
};
typedef struct node node;
bool isleaf(node *root) {
	for(int i = 0; i < 9; ++i) {
		if(root->child[i] != nullptr) return false;
	}
	return true;
}
bool insert(string no, node *root) {
	bool flag = true;
	int len = no.length();
	int digit;
	for(int i = 0; i < len; ++i) {
		digit = no[i] - '0';
		if(root->child[digit] != nullptr) {
			if(root->child[digit]->end)
				flag = false;
			root = root->child[digit];
		}
		else {
			root->child[digit] = new node();
			root = root->child[digit];
		}
	}
	if(!root->end) root->end = true;
	else flag = false;
	return flag;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	int t;

	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string no[n];
		bool flag = true;
		node *root = new node();
		for(int i = 0; i < n; ++i) {
			cin >> no[i];
		}
		sort(no, no+n);
		for(int i = 0; i < n; ++i) {
			if(!insert(no[i], root))
				flag = false;
		}
		if(flag)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}