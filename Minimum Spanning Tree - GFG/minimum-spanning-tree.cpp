//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(n,0);
        vector<pair<int,int>> mst;
        int mstwt = 0;
        
        // {edge weight,{node,parent}}
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second.first;
            int wt = it.first;
            int parent = it.second.second;

            if(vis[node]) continue;
            
            vis[node] = 1;
            mstwt += wt;
            mst.push_back({parent,node});
            
            for(auto i : adj[node]){
                int adjnode = i[0];
                int edgewt = i[1];
                if(!vis[adjnode]) pq.push({edgewt,{adjnode,node}});
            }
        }
        
        return mstwt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends