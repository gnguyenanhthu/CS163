#include "Header.h"

void BSTree::load(char path[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) return;
	int x;
	fin >> x;
	while (x != 0)
	{
		bool added = insert(root, x);
		if (added)
			cout << x << " has been added." << endl;
		else
			cout << x << " has existed." << endl;
		fin >> x;
	}
	fin.close();
}

bool BSTree::insert(Node *&node, int x)
{
	if (node == NULL) {
		node = new Node;
		node->left = NULL;
		node->right = NULL;
		node->val = x;
		return true;
	}
	else if (node->val == x)
		return false;
	if (node->val > x) return insert(node->left, x);
	if (node->val < x) return insert(node->right, x);
}

void BSTree::ascending(Node *node)
{
	if (node == NULL)
		return;
	else
	{
		ascending(node->left);
		cout << node->val << "   ";
		ascending(node->right);
	}
}

void BSTree::printinorder()
{
	ascending(root);
}

Node* BSTree::minimum(Node *node)
{
	if (node->left == NULL)
		return node;
	minimum(node->left);
}

Node* BSTree::removex(Node *node, int x)
{
	if (node == NULL) return node;
	if (node->val < x) 
		removex(node->right, x);
	if (node->val > x)
		removex(node->left, x);
	if (node->val == x) //found x
	{
		if (node->left == NULL && node->right == NULL) //no child
		{
			delete node;
			node = NULL;
		}
		else if (node->left == NULL) //1 child
		{
			Node *tmp = node;
			node = node->right;
			delete tmp;
		}
		else if (node->right == NULL) //1 child
		{
			Node *tmp = node;
			node = node->left;
			delete tmp;
		}
		else //2 children
		{
			Node *tmp = minimum(node->right);
			node->val = tmp->val;
			node->right = removex(node->right, tmp->val);
		}
		return node;
	}
}

void BSTree::removex(int x)
{
	Node *a;
	a=removex(root, x);
}