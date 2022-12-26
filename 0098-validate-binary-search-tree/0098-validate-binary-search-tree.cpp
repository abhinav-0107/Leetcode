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
    bool check(TreeNode* curr,long long low,long long high){
        if(!curr) return true;
        if(low>=curr->val || curr->val>=high) return false;
        return check(curr->left,low,curr->val) && check(curr->right,curr->val,high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};