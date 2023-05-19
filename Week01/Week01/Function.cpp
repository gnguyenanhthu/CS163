#include "Struct.h"

void Set::init() {
	head = NULL;
}

int Set::count() {
	int c = 0;
	if (head == NULL) return c;
	Node *cur = head;
	while (cur != NULL)
	{
		++c;
		cur = cur->next;
	}
	return c;
}

void Set::add(int x) { //insert ascending
	bool check = exist(x);
	if (check) {
		cout << "This element has existed. " << endl;
		return;
	}
	else {
		Node *tmp = new Node;
		tmp->data = x;
		tmp->next = NULL;
		if (head == NULL) {
			head = tmp;
			return;
		}
		else if (x < head->data) {
			tmp->next = head;
			head = tmp;
		}
		else
		{
			Node *pre = head, *cur = pre -> next;
			while (cur!= NULL) {
				if (x > cur->data) {
					pre->next = tmp;
					tmp->next = cur;
					return;
				}
				else {
					pre = cur;
					cur = cur->next;
				}
			}
			pre->next = tmp;
		}
	}
	return;
}

bool Set::exist(int x) {
	if (head == NULL) return false;
	Node *cur = head;
	while (cur != NULL)
	{
		if (cur->data == x)
			return true;
		else
			cur = cur->next;
	}
	return false;
}

void Set::remove(int x) {
	if (head == NULL) return;
	Node *cur = head;
	while (head->data == x) {
		Node *del = cur;
		cur = cur->next;
		head = cur;
		delete del;
	}
	while (cur!= NULL) {
		if (cur->data == x) {
			Node *del = cur;
			cur = cur->next;
			delete del;
		}
		else
		cur = cur->next;
	}
}

void Set::print() {
	if (head == NULL) return;
	Node *cur = head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
}

bool Set::isSubSet(Set s) {
	if (s.count() < count()) return false;
	Node *cur1 = head, *cur2 = s.head;
	while (cur1 != NULL && cur2 != NULL) {
		while (cur1->data < cur2->data)
			cur1 = cur1->next;
		if (cur1->data != cur2->data) return false;
		cur2 = cur2->next;
	}
	return true;
}

bool Set::isSuperSet(Set s) {
	if (s.count() > count()) return false;
	Node *cur1 = head, *cur2 = s.head;
	while (cur1 != NULL && cur2 != NULL) {
		while (cur1->data > cur2->data)
			cur2 = cur2->next;
		if (cur1->data != cur2->data) 
			return false;
		cur1 = cur1->next;
	}
	return true;
}

Set Set::Union(Set s) {
	Set u;
	u.init();
	if (head == NULL && s.head == NULL) return u;
	Node *cur1 = head, *cur2 = s.head;
	while (cur1 != NULL) {
		add(cur1->data);
		cur1 = cur1->next;
	}
	while (cur2 != NULL) {
		u.add(cur2->data);
		cur2 = cur2->next;
	}
	return u;
}

Set Set::intersection(Set s) {
	Set i;
	i.init();
	if (head == NULL || s.head == NULL) return i;
	Node *cur1 = head, *cur2 = s.head;
	while (cur1 != NULL && cur2 != NULL) {
		while (cur1->data < cur2->data)
			cur1 = cur1->next;
		if (cur1->data == cur2->data)
			i.add(cur1->data);
		cur2 = cur2->next;
	}
	return i;
}

Set Set::different(Set s) {
	Set d;
	d.init();
	if ((head == NULL && s.head == NULL) || (head == NULL)) return d;
	Node *cur1 = head;
	while (cur1 != NULL) {
		d.add(cur1->data);
		cur1 = cur1->next;
	}
	Node *cur2 = s.head, *tmp = d.head;
	while (cur2 != NULL && tmp != NULL) {
		while (cur2->data < tmp->data)
			cur2 = cur2->next;
		if (cur2->data == tmp->data)
			d.remove(cur2->data);
		cur2 = cur2->next;
	}
	return d;
}

Set Set::symmetricDifference(Set s) {
	Set sd;
	sd.init();
	if (head == NULL && s.head == NULL) return sd;
	Node *cur1 = head, *cur2 = s.head;
	while (cur1 != NULL && cur2 != NULL) {
		while (cur1->data < cur2->data) {
			sd.add(cur1->data);
			cur1 = cur1->next;
		}
		if (cur1->data == cur2->data) {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		sd.add(cur2->data);
		cur2 = cur2->next;
		}
	return sd;
}

Set Set::clone() {
	Set c;
	c.init();
	if (head == NULL) return c;
	Node *cur = head;
	while (cur != NULL)
	{
		c.add(cur->data);
		cur = cur->next;
	}
	return c;
}

void Set::toArray(int *a, int &n) {
	if (head == NULL) return;
	a = new int[n];
	Node *cur = head;
	for (int i = 0; i < n; i++) {
		a[i] = cur->data;
		cur = cur->next;
	}
}

void Set::clear() {
	Node *cur = head;
	while (cur != NULL) {
		Node *del = cur;
		cur = cur->next;
		head = cur;
		delete del;
	}
}