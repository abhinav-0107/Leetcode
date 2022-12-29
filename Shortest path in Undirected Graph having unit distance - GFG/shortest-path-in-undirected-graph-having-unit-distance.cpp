//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edg,int n,int m,int src){
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int u=edg[i][0];
            int v=edg[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty()){
            auto curr=q.front();
            int u=curr.first;
            int d=curr.second;
            q.pop();
            for(auto node:adj[u]){
                if(dis[node]==1e9)q.push({node,d+1});
                dis[node]=min(dis[node],d+1);
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends