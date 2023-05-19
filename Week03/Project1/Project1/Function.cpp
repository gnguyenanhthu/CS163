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
		bool added = insert(root,x);
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

void BSTree::preorder(Node *node)
{
	if (node != NULL)
	{
		cout << node->val << "   ";
		preorder(node->left);
		preorder(node->right);
	}
}

void BSTree::preorder()
{
	return preorder(root);
}

void BSTree::ascending(Node *node)
{
	if (node != NULL)
	{
		ascending(node->left);
		cout<<node->val<<"   ";
		ascending(node->right);
	}
}

void BSTree::ascending() 
{
	return ascending(root);
}

void BSTree::decending(Node *node)
{
	if (node != NULL)
	{
		decending(node->right);
		cout << node->val << "   ";
		decending(node->left);
	}
}

void BSTree::decending()
{
	return decending(root);
}

void BSTree::postorder(Node *node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->val << "   ";
	}
}

void BSTree::postorder()
{
	return postorder(root);
}

int BSTree::height(Node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int hleft, hright;
		hleft = height(node->left);
		hright = height(node->right);
		if (hleft > hright)
			return hleft + 1;
		else
			return hright + 1;
	}
}

int BSTree::height()
{
	return height(root);
}

Node* BSTree::minimum(Node *node)
{
	if (node->left == NULL)
		return node;
	minimum(node->left);
}

Node* BSTree::minimum()
{
	return minimum(root);
}

Node* BSTree::maximum(Node *node)
{
	if (node->right == NULL)
		return node;
	maximum(node->right);
}

Node* BSTree::maximum()
{
	return maximum(root);
}

Node* BSTree::findkey(Node *node, int x) 
{
	if (node->val == x)
		return node;
	else if (node == NULL)
		return NULL;
	if (node->val > x) return findkey(node->left, x);
	if (node->val < x) return findkey(node->right, x);
}

Node* BSTree::successor(Node *node, int x)
{
	Node *key = findkey(node, x);
	if (key == NULL)
		return key;
	if (key->right != NULL)
		return minimum(key->right);
	else
	{
		Node *cur = NULL;
		while (node != NULL) 
		{
			if (key->val < node->val)
			{
				cur = node;
				node = node->left;
			}
			else if (key->val > node->val)
				node = node->right;
			else
				break;
		}
		return cur;
	}
}

Node* BSTree::successor(int x)
{
	return successor(root, x);
}

Node* BSTree::predecessor(Node *node, int x)
{
	Node *key = findkey(node, x);
	if (key == NULL)
		return key;
	if (key->left != NULL)
		return maximum(key->left);
	else
	{
		Node *cur = NULL;
		while (node != NULL)
		{
			if (key->val > node->val)
			{
				cur = node;
				node = node->right;
			}
			else if (key->val < node->val)
				node = node->left;
			else
				break;
		}
		return cur;
	}

}

Node* BSTree::predecessor(int x)
{
	return predecessor(root, x);
}