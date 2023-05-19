#include "Header.h"

int main() {
	LinearProbingHashTable h;
	int n, m, a[100];
	cout << "Input n: "; cin >> n;
	cout << "Input mod (m>n): "; cin >> m;
	h.createHashTable(m, a, n);
	h.print(m,a);
	system("pause");
	return 0;
}