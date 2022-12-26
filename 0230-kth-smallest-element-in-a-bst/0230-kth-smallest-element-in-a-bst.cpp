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
    int target=-1,count=1;
    void dfs(TreeNode* curr,int k){
        if(!curr) return;
        if(target==-1)dfs(curr->left,k);
        if(count++==k) target=curr->val;
        if(target==-1)dfs(curr->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
//      Inorder of BST is always Sorted!
        dfs(root,k);
        return target;
    }
};