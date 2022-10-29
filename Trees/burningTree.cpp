#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newNode(int key)
{
	TreeNode* temp = new TreeNode;
	temp->val = key;
	temp->left = temp->right = NULL;
	return (temp);
}

unordered_map<TreeNode*, vector<TreeNode*> > map_;

void buildMap(TreeNode* node, TreeNode* parent)
{
	if (node == NULL)
		return;
	if (map_.find(node) == map_.end()) {
		vector<TreeNode*> vec;
		map_[node] = vec;
		if (parent != NULL) {
			map_[node].push_back(parent);
			map_[parent].push_back(node);
		}
		buildMap(node->left, node);
		buildMap(node->right, node);
	}
}
void burnTree(TreeNode* root, TreeNode* target)
{
	vector<int> res;
	if (root == NULL)
		return;
	buildMap(root, NULL);
	if (map_.find(target) == map_.end()) {
		cout << "Target Not found" << endl;
		return;
	}
	unordered_set<TreeNode*> visited;
	queue<TreeNode*> q;
	q.push(target);
	visited.insert(target);
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			TreeNode* node = q.front();
			q.pop();
			cout << node->val << " ";
			for (auto next : map_[node]) {
				if (visited.find(next) != visited.end())
					continue;
				visited.insert(next);
				q.push(next);
			}
		}
		cout << endl;
	}
}

int main()
{
	TreeNode* root = newNode(12);
	root->left = newNode(13);
	root->right = newNode(10);
	root->right->left = newNode(14);
	root->right->right = newNode(15);
	TreeNode* left = root->right->left;
	TreeNode* right = root->right->right;
	left->left = newNode(21);
	left->right = newNode(24);
	right->left = newNode(22);
	right->right = newNode(23);
	burnTree(root, left);
	cout << endl;
}
