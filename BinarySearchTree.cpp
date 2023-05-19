#include <iostream>
using namespace std;
struct Node {
	int val;
	Node*pLeft, *pRight;
};
class BSTree {
public:
	BSTree() {pRoot = NULL;}
	bool insert(Node*&node,int x);
	void removeall(Node*node);
	Node* search(int x);
	Node* seach1(int x);
	void printlnr();
	void printleaves(Node*cur);
private:
	void printLNR(Node*cur);
	Node * searchinternal(int x, Node*p);
	Node * pRoot;
};
void BSTree::removeall(Node*node) {
	if (node != NULL) {
		removeall(node->pLeft);
		removeall(node->pRight);
		delete node;
		node = NULL;
	}
}
/*bool BSTree::insert(int x) {
	Node*cur = pRoot;
	if (pRoot == NULL) {
		pRoot = new Node;
		cur = pRoot;
		pRoot->val = x;
		return true;
	}
	Node* tmp=NULL;
	int check = 0;
	while (cur!=NULL) {
		if (cur->val < x) {
			tmp = cur;
			cur = cur->pLeft;
			check = 1;
		}
		if (cur->val > x) {
			tmp = cur;
			cur = cur->pRight;
			check = 2;
		}
		if (cur->val == x) {
			return false;
		}
	}
	if (check == 1) {
		tmp->pLeft = new Node;
		cur = tmp->pLeft;
		cur->val = x;
		cur->pLeft = NULL;
		cur->pRight = NULL;
		return true;
	}
	if (check == 2) {
		tmp->pRight = new Node;
		cur = tmp->pRight;
		cur->val = x;
		cur->pLeft = NULL;
		cur->pRight = NULL;
		return true;
	}
}*/ // this is correct, but there is something better
bool BSTree::insert(Node*&node, int x) {
	if(node == NULL) {
		node = new Node;
		node->pLeft = NULL;
		node->pRight = NULL;
		node->val = x;
		return true;
	}
	else if (node->val == x) return false;
	if (node->val > x) return insert(node->pLeft, x);
	if (node->val < x) return insert(node->pRight , x);
}
Node* BSTree::search(int x) {
	Node*cur = pRoot;
	while (cur != NULL && cur->val != x) {
		if (cur->val > x) cur = cur->pLeft;
		else cur = cur->pRight;
	}
	return cur;
}
Node* BSTree::searchinternal(int x, Node* p) {
	if (pRoot == NULL) return NULL;
	if (pRoot->val == x) return p;
	if (pRoot->val > x) return searchinternal(x, p->pLeft);
	else return searchinternal(x, p->pRight);
}
Node*BSTree::seach1(int x){
	return searchinternal(x, pRoot);
}//hai cai nay xai chung, search1 la de cho end-user. it would be easier for end-user that way
void BSTree::printLNR(Node*cur) {
	if (cur != NULL) {
		cout << cur->val << " ";
		printLNR(cur->pLeft);	
		printLNR(cur->pRight);
	}
}
void BSTree::printlnr() {
	return printLNR(pRoot);
}
void BSTree::printleaves(Node*cur) {
	if (cur != NULL) {
		printleaves(cur->pLeft);
		if (cur->pLeft == NULL && cur->pRight == NULL) cout << cur->val << " ";
		printleaves(cur->pRight);
	}
}

//find height of the tree, print only from x to y
int main() {
	Node*root; root = NULL;
	BSTree tree;
	int x = 0;
	for (int i = 0; i < 15; i++){
		cin >> x;
		tree.insert(root, x);
	}
	tree.printlnr();
	system("pause");
}