class Solution{
    public:
    vector<int> bottomView(Node *root){
        vector<int> ans;
        if(!root) return ans;
        map<int,int>mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            Node* node=q.front().second;
            int vertical=q.front().first;
            q.pop();
            mp[vertical]=node->data;
            if(node->left) q.push({vertical-1,node->left});
            if(node->right) q.push({vertical+1,node->right});
        }
        for(auto i:mp) ans.push_back(i.second);
        return ans;
    }
};
