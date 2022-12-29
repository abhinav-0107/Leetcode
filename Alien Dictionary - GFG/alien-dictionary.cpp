//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends