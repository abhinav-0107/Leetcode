//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfstopo(int curr,vector<pair<int,int>> adj[],vector<int>& vis,stack<int>& st){
        vis[curr]=1;
        for(auto node:adj[curr]){
            int u=node.first;
            if(!vis[u]) dfstopo(u,adj,vis,st);
        }
        st.push(curr);
    }
  
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edg){
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u=edg[i][0];
            int v=edg[i][1];
            int wt=edg[i][2];
            adj[u].push_back({v,wt});
        }    
        
        vector<int> vis(n,0);
        stack<int>st;
        for(int node=0;node<n;node++){
            if(!vis[node]) dfstopo(node,adj,vis,st);
        }
        
        vector<int>dis(n,1e9);
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto i:adj[node]){
                int v=i.first;
                int wt=i.second;
                dis[v]=min(dis[v],wt+dis[node]);
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends