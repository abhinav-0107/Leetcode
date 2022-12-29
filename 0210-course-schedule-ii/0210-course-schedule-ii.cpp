class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto i:pre) adj[i[1]].push_back(i[0]);
        vector<int> topo;
        vector<int> in(n,0);
        queue<int>q;
        for(int node=0;node<n;node++){
            for(auto j:adj[node]) in[j]++;
        }
        for(int node=0;node<n;node++){
            if(!in[node]) q.push(node);  
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(!in[i]) q.push(i);
            }
        }
        if(topo.size()!=n) return {};
        return topo;
    }
};