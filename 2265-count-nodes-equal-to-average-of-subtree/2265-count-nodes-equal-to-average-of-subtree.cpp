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
    int count=0;
    void f(TreeNode* head,int& sum,int& n){
        if(!head) return;
        sum+=head->val;
        n++;
        f(head->left,sum,n);
        f(head->right,sum,n);
    }
    
    void dfs(TreeNode* curr){
        if(!curr) return ;
        int sum=0,n=0;
        f(curr,sum,n);
        if(curr->val==floor(sum/n))count++;
        dfs(curr->left);
        dfs(curr->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};