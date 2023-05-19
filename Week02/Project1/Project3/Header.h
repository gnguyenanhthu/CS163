#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <iostream>
using namespace std;

class QuadraticProbingHashtable
{
private:
	int m;
	int a[100];
public:
	void createHashTable(int m, int a[], int n);
	void print(int m, int a[]);
};

#endif