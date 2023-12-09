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
    
    void tra(TreeNode* curr,vector<int>&ans,TreeNode* root){
        if(!curr)return;
        tra(curr->left,ans,root);
        ans.push_back(curr->val);
        tra(curr->right,ans,root);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>ans;
        tra(curr,ans,root);
        return ans;
    }
};