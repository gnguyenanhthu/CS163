//
//  main.cpp
//  2018Sum_CS163_2_W1b
//


#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* pNext;
};

class OrderedList {
public:
    void addX(int x);
    void removeX(int x);
    void display();
    void merge(OrderedList& b);
    Node* search(int x);
    
    //constructors
    OrderedList() {
        pHead = NULL;
    }
    //destructor
    ~OrderedList();

private:
    Node* pHead;
};

int main() {
    OrderedList a;
    a.addX(1);
    a.addX(3);
    a.addX(5);
    a.display();
    
    OrderedList b;
    b.addX(0);
    b.addX(2);
    b.addX(10);
    b.addX(12);
    b.display();
    
    b.merge(a);
    a.display();
    b.display();
    
    return 0;
}

OrderedList::~OrderedList() {
    Node* tmp=pHead;
    while (pHead) {
        pHead = pHead->pNext;
        delete tmp;
        tmp = pHead;
    }
}

void OrderedList::addX(int x) {
    if(pHead==NULL||pHead->val>=x){
        Node* n=new Node;
        n->val=x;
        n->pNext=pHead;
        pHead=n;
        return;
    }
    
    Node*tmp=pHead;
    while(tmp->pNext!=NULL&&tmp->pNext->val<x){
        tmp=tmp->pNext;
    }
    
    Node*n=new Node;
    n->val=x;
    n->pNext=tmp->pNext;
    tmp->pNext=n;
}

void OrderedList::display() {
    Node* cur=pHead;
    cout << "This is the list: ";
    while (cur) {
        cout << cur->val << " ";
        cur = cur->pNext;
    }
    cout << endl;
}

void OrderedList::merge(OrderedList& b) {
    if (this==&b) return;
    while (b.pHead!=NULL) {
        addX(b.pHead->val);
        Node* tmp = b.pHead;
        b.pHead = b.pHead->pNext;
        delete tmp;
    }
}

//searching for x in an OrderedList
Node* OrderedList::search(int x) {
    Node *cur = pHead;
    while(cur!=NULL && cur->val <= x)
    {
        if(cur->val == x) return cur;
        cur = cur->pNext;
    }
    return NULL;
}

//searching for x in a sorted array
int binarySearch(int* a, int n, int x) {
    int max = n - 1;
    int min = 0;
    int mid;
    while (max >= min){
        mid = (max + min)/2;
        if (a[mid] == x){
            return mid;
        }
        else if (a[mid] < x){
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    return -1;
}

