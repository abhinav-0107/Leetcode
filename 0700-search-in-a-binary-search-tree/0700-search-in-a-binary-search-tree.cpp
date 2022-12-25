/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* target=NULL;
    void bst(TreeNode* curr,int val){
        if(!curr) return;
        if(curr->val==val) target=curr;
        if(val<curr->val) searchBST(curr->left,val);
        if(curr->val<val) searchBST(curr->right,val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        bst(root,val);
        return target;
    }
};