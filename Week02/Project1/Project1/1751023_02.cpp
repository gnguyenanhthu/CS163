#include "Header.h"

int main() {
	ChainingHashtable h;
	int n = 15;
	h.createHashTable(n);
	h.print();
	system("pause");
	return 0;
}