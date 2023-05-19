#include "Header.h"

void LinearProbingHashTable::createHashTable(int m, int a[], int n) {
	if (m < n) {
		cout << "Not enough space." << endl;
		return;
	}
	for (int i = 0; i < m; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Input x[" << i << "] :";
		cin >> x;
		int k = x%m;
		bool insert = false;
		while (insert == false) {
			if (a[k] == -1) {
				a[k] = x;
				insert = true;
			}
			if (k > m) k = 0;
			else ++k;
		}
	}
}


void LinearProbingHashTable::print(int m, int a[]) {
	for (int i = 0; i < m; i++)
	{
		if (a[i] != -1)
			cout << "At value " << i << " we have" << a[i] << endl;
	}
}

