class Solution {
  public:
    void markparent(Node* curr,map<Node*,Node*>& parent){
        if(!curr) return;
        if(curr->left) parent[curr->left]=curr;
        if(curr->right) parent[curr->right]=curr;
        markparent(curr->left,parent);
        markparent(curr->right,parent);
    }
    
    Node* startnode;
    void find(Node* curr,int target){
        if(!curr) return ;
        if(curr->data==target){
            startnode=curr;
            return;
        }
        find(curr->left,target);
        find(curr->right,target);
    }
  
    int minTime(Node* root, int target){
        if(!root) return {};
        map<Node*,Node*> parent;
        markparent(root,parent);
        map<Node*,bool>vis;
        queue<Node*>q;
        find(root,target);
        q.push(startnode);
        vis[startnode]=true;
        int time=-1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            time++;
        }
        return time;
    }
};
