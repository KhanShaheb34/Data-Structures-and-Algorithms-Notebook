#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void reverseLevelOrder(node* root) {
	stack <node *> S;
	queue <node *> Q;
	Q.push(root);

	while (Q.empty() == false) {
		root = Q.front();
		Q.pop();
		S.push(root);

		if (root->right)
			Q.push(root->right);
		if (root->left)
			Q.push(root->left);
	}

	while (S.empty() == false) {
		root = S.top();
		cout << root->data << " ";
		S.pop();
	}
}

node* newNode(int data) {
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}

int main() {
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}
