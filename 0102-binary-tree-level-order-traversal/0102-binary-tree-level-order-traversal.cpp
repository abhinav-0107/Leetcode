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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        vector<int>v;
        queue<TreeNode*>q;
        TreeNode * temp= new TreeNode(INT_MAX);
        q.push(root);
        q.push(temp);
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr==temp){
                ans.push_back(v);
                if(q.front()==temp && q.back()==temp)break;
                q.push(temp);
                q.pop();
                v.clear();
                continue;
            }
            v.push_back(curr->val);
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return ans;
    }
};