class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* curr) {
        if(!curr) return;
        flatten(curr->right);
        flatten(curr->left);
        curr->right=prev;
        curr->left=NULL;
        prev=curr;
    }
};