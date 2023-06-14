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
    int ans=1e9,pre=1e9;
    void dfs(TreeNode* curr){
        if(!curr)return;
        dfs(curr->left);
        if(pre==1e9)pre=curr->val;
        else{
            ans=min(ans,abs(curr->val-pre));
            pre=curr->val;
        }        
        dfs(curr->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        dfs(root);    
        return ans;
    }
};