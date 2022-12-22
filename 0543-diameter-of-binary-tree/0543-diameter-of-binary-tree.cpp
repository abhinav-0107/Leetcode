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
    int maxi=0;
    void dfs(TreeNode* curr){
        if(!curr) return;
        int lh=height(curr->left);
        int rh=height(curr->right);
        maxi=max(maxi,lh+rh);
        dfs(curr->left);
        dfs(curr->right);
    }

    int height(TreeNode* node){
        if(!node) return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};