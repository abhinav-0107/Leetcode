class Solution {
public:
    vector<vector<int>>allpaths;
    void dfs(int curr,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path,int n){
        vis[curr]=1;
        path.push_back(curr);
        if(curr==n-1){
            allpaths.push_back(path);
            return;
        }    
        for(auto node: adj[curr]){
            if(!vis[node] || node==n-1){
                dfs(node,adj,vis,path,n);
                path.pop_back();
                vis[node]=0;
            }    
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> path;
        dfs(0,adj,vis,path,n);
        return allpaths;
    }
};