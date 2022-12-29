class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        // Formation of adjacency list for the directed Graph
        vector<int> adj[k];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(dict[i].size(),dict[i+1].size());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }    
            }
        }
        
        vector<int>topo;
        queue<int>q;
        vector<int> in(k,0);
        for(int node=0;node<k;node++){
            for(auto j:adj[node]) in[j]++;
        }
        for(int node=0;node<k;node++){
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
        
        string ans="";
        for(auto i:topo)ans+=char('a'+i);
        return ans;
    }
};
