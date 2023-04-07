class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            for(auto d:dir){
                int r=node.first+d.first;
                int c=node.second+d.second;
                if(r<m && r>=0 && c<n && c>=0 && grid[r][c] && !vis[r][c]){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(grid[0][j] && !vis[0][j]) bfs(0,j,grid,vis,m,n);
            if(grid[m-1][j] && !vis[m-1][j]) bfs(m-1,j,grid,vis,m,n);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0] && !vis[i][0]) bfs(i,0,grid,vis,m,n);
            if(grid[i][n-1] && !vis[i][n-1]) bfs(i,n-1,grid,vis,m,n);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};