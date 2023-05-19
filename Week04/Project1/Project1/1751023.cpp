#include "Header.h"

int main()
{
	BSTree bst;
	int x;
	bst.load("D:\\APCS\\CS163\\Week03\\input.txt");
	cout << "Input x: ";
	cin >> x;
	bst.removex(x);
	bst.printinorder();
	system("pause");
	return 0;
}