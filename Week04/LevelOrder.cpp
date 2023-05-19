struct node
{
    int data;
    node* left;
    node* right;
};

struct QNode{
    node *data;
    QNode *next;
};

struct Queue{
    QNode *head;
    QNode *tail;
};

void levelOrder(node *root);
void enqueue(Queue &q, node *n);
void dequeue(Queue &q);

void levelOrder(node *root) {
    Queue q;
    q.head=NULL; q.tail=NULL;
    enqueue(q,root);
    while(q.head){
        QNode *tmp = q.head;
        if(tmp->data->left) 
            enqueue(q, tmp->data->left);
        if(tmp->data->right) 
            enqueue(q, tmp->data->right);
        dequeue(q);
    }
}

void enqueue(Queue &q, node *n){
    QNode *tmp = new QNode;
    tmp->data=n;
    tmp->next=NULL;
    if (q.head==NULL){
        q.head=tmp;
        q.tail=tmp;
    }
    else{
        q.tail->next=tmp;
        q.tail=tmp;
    }
}

void dequeue(Queue &q){
    QNode *del=q.head;
    q.head=q.head->next;
    cout<<del->data->data<<" ";
    delete del;
}