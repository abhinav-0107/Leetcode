//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void dfs1(int node,vector<int> adj[],vector<int>& vis,stack<int>& st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs1(it,adj,vis,st);
	    }
	    st.push(node);
	}
	
	void dfs2(int node,vector<int> adjT[],vector<int>& vis){
	    vis[node]=1;
	    for(auto it:adjT[node]){
	        if(!vis[it]) dfs2(it,adjT,vis);
	    }
	}
	

    int kosaraju(int n, vector<int> adj[]){
        
        // Step - 1
        vector<int> vis(n,0);
        stack<int> st;
        for(int node=0;node<n;node++){
            if(!vis[node]) dfs1(node,adj,vis,st);
        }
        
        // Step -2 
        vector<int> adjT[n];
        for(int node=0;node<n;node++){
            vis[node]=0;
            for(auto it:adj[node]) adjT[it].push_back(node);
        }
        
        // Step - 3 
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,adjT,vis);
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends