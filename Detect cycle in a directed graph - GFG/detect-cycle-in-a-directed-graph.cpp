//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int n, vector<int> adj[]){
        vector<int> indegree(n,0);
        vector<int> topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto j:adj[i]) indegree[j]++;
        }
        for(int node=0;node<n;node++){
            if(!indegree[node]) q.push(node);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
        }
        return topo.size()!=n;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends