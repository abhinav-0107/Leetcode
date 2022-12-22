// Optimal
// TC->O(Number of Nodes) && S->O(height of the Tree)

class Solution {
public:
    void dfs(TreeNode* curr,int lvl,vector<int>& ans){
        if(!curr) return;
        if(lvl==ans.size()) ans.push_back(curr->val);
        dfs(curr->right,lvl+1,ans);
        dfs(curr->left,lvl+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,0,ans);
        return ans;
    }
};