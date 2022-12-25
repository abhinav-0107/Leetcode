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
    TreeNode* tree(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd,map<int,int>& ind){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(pre[preStart]);
        int inRoot=ind[root->val];
        int numsleft=inRoot-inStart;
        root->left=tree(pre,preStart+1,preStart+numsleft,in,inStart,inRoot-1,ind);
        root->right=tree(pre,preStart+numsleft+1,preEnd,in,inRoot+1,inEnd,ind);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre,vector<int>& in) {
        map<int,int>ind;
        for(int i=0;i<in.size();i++) ind[in[i]]=i;
        return tree(pre,0,pre.size()-1,in,0,in.size()-1,ind);
    }
};