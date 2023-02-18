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
    
    void tra(TreeNode* curr){
        if(!curr)return;
        TreeNode* temp=curr->left;
        curr->left=curr->right;
        curr->right=temp;
        tra(curr->left);
        tra(curr->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* curr=root;
        tra(curr);
        return root;
    }
};