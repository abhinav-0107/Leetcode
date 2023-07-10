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
    
    void tar(TreeNode* curr,int depth,int &min){
        if(!curr)return;
        if(!curr->left && !curr->right){
            if(depth<min)min=depth;
            return;
        }
        tar(curr->left,depth+1,min);
        tar(curr->right,depth+1,min);
    }
    
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int min=INT_MAX;
        tar(root,1,min);
        return min;
    }
};