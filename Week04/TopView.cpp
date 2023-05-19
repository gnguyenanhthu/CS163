struct node
{
    int data;
    node *left;
    node *right;
};

void topView(node *root);
void Left(node *tmp);
void Right(node *tmp);

void topView(node *root) {
	if (root->left) 
		Left(root->left);
	cout<<root->data<<" ";
	if (root->right)
		Right(root->right);
}

void Left(node *tmp) {
	if (tmp == NULL) return;
	Left(tmp->left);
    cout << tmp->data << " ";
}
void Right(node *tmp) {
	if (tmp == NULL) return;
	cout << tmp->data << " ";
    Right(tmp->right);
}