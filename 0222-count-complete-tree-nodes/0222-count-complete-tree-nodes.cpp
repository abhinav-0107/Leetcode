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

// Time Comp -> O((logn)^2) + Space Comp -> O(logn)

class Solution {
public:
    int l(TreeNode* node){
        if(!node) return 0;
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    
    int r(TreeNode* node){
        if(!node) return 0;
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
    
    int count(TreeNode* curr){
        if(!curr) return 0;
        int lh=l(curr);
        int rh=r(curr);
        if(lh==rh) return (1<<rh)-1;
        return 1+count(curr->left)+count(curr->right);
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return count(root);
    }
};