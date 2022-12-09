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
    int ans=0;
    void tra(TreeNode* it,int a){
        if(!it) return;
        ans=max(ans,abs(it->val-a));
        tra(it->left,a);
        tra(it->right,a);
    }
    
    void dfs(TreeNode* curr){
        if(!curr) return ;
        tra(curr,curr->val);
        dfs(curr->left);
        dfs(curr->right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};