#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;
#include <fstream>

struct Node {
	int val;
	Node *left, *right;
};

class BSTree {
public:
	BSTree() { root = NULL; }
	void load(char path[]);
	void removex(int x);
	void printinorder();
private:
	Node *root;
	bool insert(Node *&node, int x);
	void ascending(Node *node);
	Node* minimum(Node *node);
	Node* removex(Node *node, int x);
};

#endif