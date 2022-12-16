class Solution {
public:
    int count=0;
    int c=0;
    int paths(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n){
        if(i>=m || j>=n)return 0;
        if(grid[i][j]==2){
            if(c==count-1)return 1;
            return 0;
        }     
//      Down
        int d=0;
        if(i+1<m && !vis[i+1][j] && (grid[i+1][j]==0 || grid[i+1][j]==2)){
            vis[i][j]=1;
            c++;
            d=paths(i+1,j,grid,vis,m,n);
            c--;
            vis[i][j]=0;
        }
//      Left
        int l=0;
        if(j-1>=0 && !vis[i][j-1] && (grid[i][j-1]==0 || grid[i][j-1]==2)){
            vis[i][j]=1;
            c++;
            l=paths(i,j-1,grid,vis,m,n);
            c--;
            vis[i][j]=0;
        }
//      Right
        int r=0;
        if(j+1<n && !vis[i][j+1] && (grid[i][j+1]==0 || grid[i][j+1]==2)){
            vis[i][j]=1;
            c++;
            r=paths(i,j+1,grid,vis,m,n);
            c--;
            vis[i][j]=0;
        }
//      up
        int u=0;
        if(i-1>=0 && !vis[i-1][j] && (grid[i-1][j]==0 || grid[i-1][j]==2)){
            vis[i][j]=1;
            c++;
            u=paths(i-1,j,grid,vis,m,n);
            c--;
            vis[i][j]=0;
        }
        return d+l+r+u;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i,j;
        bool f=false;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1){
                    f=true;
                    break;
                }   
            }
            if(f)break;
        }
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]!=-1) count++;
            }
        }
        cout<<count;
        vector<vector<int>>vis(m,vector<int>(n,0));
        return paths(i,j,grid,vis,m,n);
    }
};