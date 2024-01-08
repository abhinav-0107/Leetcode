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
    
    void tra(TreeNode* curr,int &sum,int h,int l){
        if(!curr)return;
        if(curr->val<=h && curr->val>=l) sum+=curr->val;
        tra(curr->left,sum,h,l);
        tra(curr->right,sum,h,l);
    }
    
    int rangeSumBST(TreeNode* root, int l, int h) {
        if(!root)return NULL;
        int sum=0;
        tra(root,sum,h,l);
        return sum;
    }
};