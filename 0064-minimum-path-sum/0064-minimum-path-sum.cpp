class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prevrow(n,0);
        for(int i=0;i<m;i++){
            vector<int>currrow(n,0);
            for(int j=0;j<n;j++){
                if(!i && !j) currrow[0]=grid[0][0];
                else{
                    int up=100000,left=100000; 
                    if(i>0) up=grid[i][j]+prevrow[j];
                    if(j>0) left=grid[i][j]+currrow[j-1];
                    currrow[j]=min(up,left);
                }
            }
            prevrow=currrow;
        }
        return prevrow[n-1];
    }
};