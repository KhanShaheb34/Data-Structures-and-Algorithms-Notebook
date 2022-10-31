#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

int isLeaf(node *node)
{
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;
	return 0;
}

int isSumTree(node* node)
{
	if(node == NULL)
	return 0;
	
	int ls;
	int rs;
	
	ls = isSumTree(node->left);
	if(ls == -1)
  	return -1;
	
	rs = isSumTree(node->right);
	if(rs == -1)
	  return -1;	
	if(isLeaf(node) || ls + rs == node->data)
	  return ls + rs + node->data;
	else
  	return -1;
}

node* newNode(int data)
{
	node* node1 = new node();
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;
	return(node1);
}

int main()
{
	node *root = newNode(26);
	root->left = newNode(10);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->right->right = newNode(3);
	
	int total = isSumTree(root);
	if(total != -1 && total == 2*(root->data))
	  cout<<"Tree is a Sum Tree";
	else
  	cout<<"Given Tree is not sum Tree";
	return 0;
}
