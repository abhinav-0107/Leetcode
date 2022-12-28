class Solution {
public:
    bool check(int start,vector<vector<int>>& adj,vector<int>& color){
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int prev=q.front();
            q.pop();
            for(auto curr: adj[prev]){
                if(color[curr]==-1){
                    color[curr]=!color[prev];
                    q.push(curr);
                }
                else if(color[curr]==color[prev]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !check(i,adj,color)) return false; 
        }
        return true;
    }
};