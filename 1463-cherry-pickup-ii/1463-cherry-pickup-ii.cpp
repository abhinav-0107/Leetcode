// Recursion

// class Solution {
// public:
//     int f(int i,int j1,int j2, vector<vector<int>>& grid,int m,int n){
//         if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
//         if(i==m-1){
//             if(j1==j2) return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         }
// //      Explore all the movements of both robots
//         int maxi=INT_MIN;
//         for(int dj1=-1;dj1<=+1;dj1++){
//             for(int dj2=-1;dj2<=+1;dj2++){
//                 if(j1==j2) maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid,m,n));
//                 else maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid,m,n));
//             }
//         }
//         return maxi;
//     }
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return f(0,0,n-1,grid,m,n);
//     }
// };



//Memoizartion

class Solution {
public:
    int f(int i,int j1,int j2, vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//      Explore all the movements of both robots
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                if(j1==j2) dp[i][j1][j2]=maxi=max(maxi, grid[i][j1] + f(i+1,j1+dj1,j2+dj2,grid,m,n,dp));
                else dp[i][j1][j2]=maxi=max(maxi, grid[i][j1] + grid[i][j2] + f(i+1,j1+dj1,j2+dj2,grid,m,n,dp));
            }
        }
        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,grid,m,n,dp);
    }
};



// Tabulation

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
// //      Base Case
//         for(int j1=0;j1<n;j1++){
//             for(int j2=0;j2<n;j2++){
//                 if(j1==j2) dp[m-1][j1][j2]=grid[m-1][j1];
//                 else dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
//             }
//         }
//         for(int i=m-2;i>=0;i--){
//             for(int j1=0;j1<n;j1++){
//                 for(int j2=0;j2<n;j2++){
//                     int maxi=INT_MIN;
//                     for(int dj1=-1;dj1<=+1;dj1++){
//                         for(int dj2=-1;dj2<=+1;dj2++){
//                             int val=0;
//                             if(j1==j2) val=grid[i][j1];
//                             else val=grid[i][j1]+grid[i][j2];
//                             if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)val+=dp[i+1][j1+dj1][j2+dj2];
//                             else val+=-1e9;
//                             maxi=max(maxi,val);
//                         }
//                     }  
//                     dp[i][j1][j2]=maxi;                      
//                 }
//             }
//         }
        
//         return dp[0][0][n-1];
//     }
// };



//Space Optimization

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> prev(n,vector<int>(n)),curr(n,vector<int>(n));
// //      Base Case
//         for(int j1=0;j1<n;j1++){
//             for(int j2=0;j2<n;j2++){
//                 if(j1==j2) prev[j1][j2]=grid[m-1][j1];
//                 else prev[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
//             }
//         }
//         for(int i=m-2;i>=0;i--){
//             for(int j1=0;j1<n;j1++){
//                 for(int j2=0;j2<n;j2++){
//                     int maxi=INT_MIN;
//                     for(int dj1=-1;dj1<=+1;dj1++){
//                         for(int dj2=-1;dj2<=+1;dj2++){
//                             int val=0;
//                             if(j1==j2) val=grid[i][j1];
//                             else val=grid[i][j1]+grid[i][j2];
//                             if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)val+=prev[j1+dj1][j2+dj2];
//                             else val+=-1e9;
//                             maxi=max(maxi,val);
//                         }
//                     }  
//                     curr[j1][j2]=maxi;                      
//                 }
//             }
//             prev=curr;
//         }
        
//         return prev[0][n-1];
//     }
// };

