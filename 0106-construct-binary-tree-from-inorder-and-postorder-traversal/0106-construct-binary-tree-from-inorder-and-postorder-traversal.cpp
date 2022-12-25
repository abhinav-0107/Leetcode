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
    TreeNode* tree(vector<int>& in,int inStart,int inEnd,vector<int>& post,int postStart,int postEnd,map<int,int>& ind){
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root=new TreeNode(post[postEnd]);
        int inRoot=ind[root->val];
        int numsleft=inRoot-inStart;
        root->left=tree(in,inStart,inRoot-1,post,postStart,postStart+numsleft-1,ind);
        root->right=tree(in,inRoot+1,inEnd,post,postStart+numsleft,postEnd-1,ind);
        return root;        
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        if(in.size()!=post.size()) return NULL;
        map<int,int>ind;
        for(int i=0;i<in.size();i++) ind[in[i]]=i;
        return tree(in,0,in.size()-1,post,0,post.size()-1,ind);
    }
};