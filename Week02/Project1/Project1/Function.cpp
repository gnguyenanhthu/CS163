#include "Header.h"

void Linkedlist::init() {
	head = NULL;
	tail = NULL;
}

Node* Linkedlist::toTail() {
	Node *cur = head;
	if (head != NULL) 
	{
		while (cur->next != NULL)
			cur = cur->next;
	}
	tail = cur;
	return tail;
}

void Linkedlist::insertTail(int x) {
	Node *tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail = toTail();
		tail->next = tmp;
		tail = tmp;
	}
}

void Linkedlist::print() {
	if (head == NULL) 
	{ 
		cout << "Nothing."; 
		return;
	}
	Node *cur = head;
	while (cur != NULL) {
		cout << cur->data << "  ";
		cur = cur->next;
	}
}


void ChainingHashtable::createHashTable(int n) {
	for (int i = 0; i < m; i++) 
		a[i].init();
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Input x[" << i << "] :";
		cin >> x;
		int k = x%m;
		a[k].insertTail(x);
	}
}

void ChainingHashtable::print() {
	for (int i = 0; i < m; i++)
	{
		cout << "At value " << i << " we have: ";
		a[i].print();
		cout << endl;
	}
}