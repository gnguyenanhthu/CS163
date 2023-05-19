//
//  main.cpp
//  2018Sum_CS163_2_W3b
//

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* pLeft, *pRight;
};

struct BSTree {
public:
    BSTree() { pRoot=NULL; }
    bool insert(int x);
    bool insert2(int x);
    ~BSTree() { removeAll(pRoot); }
    Node* search(int x);
    Node* search1(int x);
    void printLNR();
    void printAllLeafNode();
    void printAllLeafNode(Node * node);
    
private:
    Node* pRoot;
    bool insert2(Node* &node, int x);
    void removeAll(Node* &root);
    Node* searchInternal(int x, Node* p);
    void printLNR(Node*root);
};

int main() {
    return 0;
}

bool BSTree::insert(int x) {
    Node*roottmp=pRoot, *tmp=NULL;
    if(pRoot==NULL)
    {
        pRoot=new Node;
        pRoot->val=x;
        pRoot->pLeft=NULL;
        pRoot->pRight=NULL;
        return true;
    }
    else if(roottmp->val==x)
        return false;
    while(roottmp!=NULL&&roottmp->val!=x)
    {
        tmp=roottmp;
        if(x<roottmp->val)
        {
            roottmp=roottmp->pLeft;
        }
        else if(x>roottmp->val)
        {
            roottmp=roottmp->pRight;
        }
    }
    if (roottmp!=NULL) //(roottmp->val==x)
        return false;
    else{
        roottmp=new Node;
        roottmp->val=x;
        roottmp->pLeft=NULL;
        roottmp->pRight=NULL;
        if ((tmp->val)>x) tmp->pLeft=roottmp;
        else tmp->pRight=roottmp;
        return true;
    }
}

bool BSTree::insert2(int x) {
    return insert2(pRoot, x);
}

bool BSTree::insert2(Node* &node, int x) {
    if (node == NULL) {
        node = new Node;
        node->val = x;
        node->pLeft = NULL;
        node->pRight = NULL;
        return true;
    }
    else if (node->val == x) return false;
    if (node->val > x) return insert2(node->pLeft, x);
    return insert2(node->pRight, x);
}

void BSTree::removeAll(Node* &root)
{
    if (root != NULL)
    {
        removeAll(root->pLeft);
        removeAll(root->pRight);
        delete root;
        root = NULL;
    }
}

Node* BSTree::search(int x) {
    Node *cur=pRoot;
    while (cur!=NULL && cur->val!=x){
        if (cur->val>x)
            cur=cur->pLeft;
        else
            cur=cur->pRight;
    }
    return cur;
}

Node * BSTree::searchInternal(int x,Node* p){
    if (p==NULL) return NULL;
    if (p->val==x) return p;
    if (p->val >x) return searchInternal(x, p->pLeft);
    else return searchInternal(x,p->pRight);
}

Node* BSTree::search1(int x) {
    return searchInternal(x, pRoot);
}
void BSTree::printLNR(Node*root){
    if (root!=NULL){
        printLNR(root->pLeft);
        cout << root->val << " ";
        printLNR(root->pRight);
    }
}
void BSTree::printLNR() {
    printLNR(pRoot);
}
void BSTree::printAllLeafNode(Node*node){
    if (node!=NULL){
        printAllLeafNode(node->pLeft);
        if(node->pLeft == NULL && node->pRight == NULL)
            cout << node->val << " ";
        printAllLeafNode(node->pRight);
    }
}
void BSTree::printAllLeafNode() {
    printAllLeafNode(pRoot);
}



















