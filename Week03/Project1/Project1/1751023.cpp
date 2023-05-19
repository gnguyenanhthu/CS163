#include "Header.h"

int main() {
	BSTree bst;
	Node *min, *max, *s, *p;
	int h, x;
	bst.load("D:\\APCS\\CS163\\Week03\\input.txt");
	cout << endl;
	
	cout << "Pre-order:  ";
	bst.preorder();
	cout << endl;
	cout << "Ascending:  ";
	bst.ascending();
	cout << endl;
	cout << "Decending:  ";
	bst.decending();
	cout << endl;
	cout << "Post-order:  ";
	bst.postorder();
	cout << endl;
	cout << endl;

	min = bst.minimum();
	cout <<"Minimum: " << min->val << endl;
	max = bst.maximum();
	cout <<"Maximum: " << max->val << endl;
	cout << endl;

	h = bst.height();
	cout << "The height of the tree is "<< h << endl;
	cout << endl;

	cin >> x;

	s = bst.successor(x);
	if (s == NULL)
		cout << "Couldn't find x." << endl;
	else
		cout <<"Successor of "<< x <<" is " << s->val << endl;

	p = bst.predecessor(x);
	if (p == NULL)
		cout << "Couldn't find x." << endl;
	else
		cout << "Predecessor of " << x << " is " << p->val << endl;

	system("pause");
	return 0;
}