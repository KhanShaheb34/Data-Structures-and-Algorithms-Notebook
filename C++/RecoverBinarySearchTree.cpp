class Solution {
    TreeNode* first, *middle, *prev, *last;
    void inorder(TreeNode* root)
    {   if(!root) return ;
        inorder(root->left)
        if(prev && (prev->val > root->val)) {
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    } 
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
