#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Linkedlist {
private:
	Node *head;
	Node *tail;
public:
	void init();
	Node *toTail();
	void insertTail(int x);
	void print();
};

class ChainingHashtable {
private:
	int m = 23;
	Linkedlist a[100];
public:
	void createHashTable(int n);
	void print();
};

#endif