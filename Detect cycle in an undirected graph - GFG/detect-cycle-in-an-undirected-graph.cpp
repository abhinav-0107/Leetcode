//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(int start,vector<int> adj[],vector<int>& vis){
        queue<pair<int,int>>q;
        q.push({start,-1});
        vis[start]=1;
        while(!q.empty()){
            int curr=q.front().first;
            int prev=q.front().second;
            q.pop();
            for(auto node:adj[curr]){
                if(!vis[node] && node!=prev){
                    q.push({node,curr});
                    vis[node]=1;
                }
                else if(node!=prev) return true;
            }
        }
        return false;
    }
 
    bool isCycle(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        for(int node=0;node<n;node++){
            if(!vis[node] && check(node,adj,vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends