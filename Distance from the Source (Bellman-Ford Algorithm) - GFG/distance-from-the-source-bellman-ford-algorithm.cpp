//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        vector<int> dis(n,1e8);
        vector<int> temp;
        dis[s]=0;
        for(int i=0;i<n;i++){
            for(auto j : edges){
                int u=j[0];
                int v=j[1];
                int wt=j[2];
                if( dis[u] + wt < dis[v]) dis[v] = dis[u] + wt;
            }
            if(i==n-2) temp=dis;
        }
        if(temp!=dis) return {-1};
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends