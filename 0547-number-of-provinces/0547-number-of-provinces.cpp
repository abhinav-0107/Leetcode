class Solution {
public:
//DFS Traversal of the components of graph
    
    void dfs(int node,vector<int>adj[],vector<int>& vis){
        vis[node]=1;
        for(auto v:adj[node]){
            if(!vis[v])dfs(v,adj,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& iscon) {
        
//Conversion of adj matrix to adj list
        int n=iscon.size();
        vector<int>adj[n];
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(iscon[u][v] && u!=v){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int v=0;v<n;v++){
            if(!vis[v]){
                count++;
                dfs(v,adj,vis);
            }
        }
        return count;
    }
};