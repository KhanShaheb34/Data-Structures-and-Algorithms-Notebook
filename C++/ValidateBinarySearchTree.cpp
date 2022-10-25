 bool isValidBST(TreeNode* root, long mi = LONG_MIN, long ma = LONG_MAX) {
        return (!root) || mi < root->val && root->val < ma &&
                isValidBST(root->left, mi, root->val) &&
                isValidBST(root->right, root->val, ma);
    }
