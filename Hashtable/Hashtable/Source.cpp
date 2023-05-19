#include<iostream>
using namespace std;

struct Element {
	int ID;
	int data;
};

class Hashtable {
public:
	void initialize(int k);
	void cleanUp();
	bool insert(Element x);
	bool search(int id, Element &found);

private:
	int n; //hash function h(ID) = ID mod n
	Element *hashArr;
};

int main(){
	return 0;

}

void Hashtable::initialize(int k) {
	n = k;
	hashArr = new Element[n];
	for (int i = 0; i < n; ++i)
		hashArr[i].ID = 0; //special value
}

void Hashtable::cleanUp() {
	n = 0;
	delete[] hashArr;
}

bool Hashtable::insert(Element x) {
	int index = x.ID%n;
	int i = index + 1;
	if (hashArr[index].ID == 0) {
		hashArr[index] = x;
		return true;
	}
	else
		while (true) { //dung dk khac
			if (index + i >= n) 
				i = -index;
			else i++;
			if (index == index + i) return false;
			if (hashArr[index + i].ID == 0) {
				hashArr[index + i] = x;
				return true;
			}
		}
}

bool Hashtable::search(int id, Element &found) {

}