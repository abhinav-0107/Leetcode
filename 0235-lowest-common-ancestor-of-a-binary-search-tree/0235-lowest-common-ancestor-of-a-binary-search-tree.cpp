/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* curr,TreeNode* p,TreeNode* q) {
        if(!curr) return NULL;
        if(p->val<curr->val && q->val<curr->val) return lowestCommonAncestor(curr->left,p,q);
        if(p->val>curr->val && q->val>curr->val) return lowestCommonAncestor(curr->right,p,q);
        return curr;
    }
};