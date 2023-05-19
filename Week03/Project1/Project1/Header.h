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
	void preorder();
	void ascending();
	void decending();
	void postorder();
	int height();
	Node* minimum();
	Node* maximum();
	Node* successor(int x);
	Node* predecessor(int x);
private:
	Node *root;
	bool insert(Node *&node, int x);
	void preorder(Node *node);
	void ascending(Node *node);
	void decending(Node *node);
	void postorder(Node *node);
	Node* minimum(Node *node);
	Node* maximum(Node *node);
	int height(Node *node);
	Node* findkey(Node *node, int x);
	Node* successor(Node *node, int x);
	Node* predecessor(Node *node, int x);
};

#endif