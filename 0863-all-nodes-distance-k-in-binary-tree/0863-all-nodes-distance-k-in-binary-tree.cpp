/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* curr,map<TreeNode*,TreeNode*>& mp){
        if(!curr) return ;
        if(curr->left) mp[curr->left]=curr;
        if(curr->right) mp[curr->right]=curr;
        parent(curr->left,mp);
        parent(curr->right,mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        map<TreeNode*,TreeNode*>mp;
        parent(root,mp);
        for(auto i:mp) cout<<i.first->val<<" "<<i.second->val<<endl;
        vector<int>ans;
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_lvl==k) break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }    
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }    
                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]]=true;
                    cout<<mp[node]->val<<endl;
                    q.push(mp[node]);
                }    
            }
            curr_lvl++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }    
        return ans;
    }
};