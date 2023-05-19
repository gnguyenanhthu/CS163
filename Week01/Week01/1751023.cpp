#include "Struct.h"

int main() {
	Set s;
	int x;

	s.init();
	cout << "There are " << s.count() << " element(s)." << endl;
	
	cout << "Input x: ";
	cin >> x;

	if (s.exist(x))
		cout << x << " has existed in the list." << endl;
	else
		cout << x << " has not existed in the list." << endl;

	s.add(x);
	s.add(1); s.add(2); s.add(3);
	cout << "Set contains: " << endl;
	s.print();

	s.remove(x);
	cout << "Set after remove: " << endl;
	s.print();

	Set a;
	a.add(1); a.add(2);
	if (s.isSubSet(a))
		cout << x << "S is subset of A." << endl;
	else
		cout << x << "S is not subset of A." << endl;

	Set b;
	b.add(1); b.add(2); b.add(3); b.add(4); b.add(5); b.add(6);
	if (s.isSuperSet(b))
		cout << x << "S is superset of B." << endl;
	else
		cout << x << "S is not superset of B." << endl;

	Set c;
	c.add(1); c.add(3); c.add(5); c.add(7);
	
	Set u;
	u = s.Union(c);
	cout << "Union: " << endl;
	u.print();

	Set i;
	i = s.intersection(c);
	cout << "Intersection: " << endl;
	i.print();
	
	Set d;
	d = s.different(c);
	cout << "Different: " << endl;
	d.print();

	Set sd;
	sd = s.symmetricDifference(c);
	cout << "Symmetric Difference: " << endl;
	sd.print();

	Set cl;
	cl = s.clone();
	cout << "Clone: " << endl;
	cl.print();

	int *m = NULL, n;
	n = s.count();
	s.toArray(m, n);
	cout << "Array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}

	s.clear(); 
	a.clear(); 
	b.clear(); 
	c.clear();
	u.clear();
	i.clear();
	d.clear();
	sd.clear();
	cl.clear();

	system("pause");
	return 0;
}