#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node* left, *right;
	int key;
};

struct Node* newNode(int key)
{
	struct Node* ptr = new Node;
	ptr->key = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

struct Node* insert(struct Node* root, int key)
{
	if (!root)
		root = newNode(key);
	else if (root->key > key)
		root->left = insert(root->left, key);
	else if (root->key < key)
		root->right = insert(root->right, key);
	return root;
}

int distanceFromRoot(struct Node* root, int x)
{
	if (root->key == x)
		return 0;
	else if (root->key > x)
		return 1 + distanceFromRoot(root->left, x);
	return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct Node* root, int a, int b)
{
	if (!root)
		return 0;

	if (root->key > a && root->key > b)
		return distanceBetween2(root->left, a, b);

	if (root->key < a && root->key < b) 
		return distanceBetween2(root->right, a, b);

	if (root->key >= a && root->key <= b)
		return distanceFromRoot(root, a) +
			distanceFromRoot(root, b);
}

int findDistWrapper(Node *root, int a, int b)
{
if (a > b)
	swap(a, b);
return distanceBetween2(root, a, b);
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	int a = 5, b = 55;
	cout << findDistWrapper(root, 5, 35);
	return 0;
}
