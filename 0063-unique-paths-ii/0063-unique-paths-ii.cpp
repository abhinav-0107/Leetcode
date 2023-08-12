class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i && !j) dp[0][0]=1;
                else{
                    int left=0,up=0;
                    if(j>0 && !grid[i][j])left=dp[i][j-1];
                    if(i>0 && !grid[i][j])up=dp[i-1][j];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};