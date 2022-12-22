class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true; // L->R
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                TreeNode* node=q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(!flag) reverse(v.begin(),v.end());
            ans.push_back(v);
            flag=!flag;
        }
        return ans;
    }
};