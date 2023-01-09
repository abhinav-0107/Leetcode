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
    
    void tra(TreeNode* root,vector<int>&ans,TreeNode* curr){
        if(!curr)return;
        ans.push_back(curr->val);
        tra(root,ans,curr->left);
        tra(root,ans,curr->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        tra(root,ans,curr);
        return ans;
    }
};