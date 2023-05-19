#include "Header.h"

void DoubleHashingHashtable::createHashTable(int m, int a[], int n) {
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
		if (a[k] == -1) {
			a[k] = x;
		}
		else {
			int p = (k % (m - 1)) + 1;
			if (a[p] == -1) {
				a[p] = x;
			}
			else {
				int j = 0, q = k + j*p;
				bool insert = false;
				while (insert == false) {
					if (a[q] == -1) {
						a[q] = x;
						insert = true;
					}
					++j;
					q = k + j*p;
				}
			}
		}
	}
}

void DoubleHashingHashtable::print(int m, int a[]) {
	for (int i = 0; i < m; i++)
	{
		if (a[i] != -1)
			cout << "At value " << i << " we have" << a[i] << endl;
	}
}