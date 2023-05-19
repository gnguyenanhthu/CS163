#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Set {
private:
	Node *head;
public:
	// initialize an empty set
	void init();
	
	// get number of elements in the current set (cardinality)
	int count();
	
	// add x to a set (if x has not existed in the set yet)
	void add(int x);
	
	// check whether x exists in the current set or not
	bool exist(int x);

	void remove(int x);
	
	// print to console, in ascending order: {1, 5, 7}
	void print();
	
	// check whether the current set is a sub set of s
	bool isSubSet(Set s);
	
	// check whether the current set is a super set of s
	bool isSuperSet(Set s);
	
	// new set with elements from both current set and s
	Set Union(Set s);
	
	// new set with elements common to current set and s
	Set intersection(Set s);
	
	// new set with elements in current set but not in s
	Set different(Set s);
	
	// new set with elements in either current s or s but not both
	Set symmetricDifference(Set s);
	
	// new set from current s
	Set clone();
	
	// convert to an array
	void toArray(int *a, int &n);
	
	// remove all elements in the current s
	void clear();
};

#endif