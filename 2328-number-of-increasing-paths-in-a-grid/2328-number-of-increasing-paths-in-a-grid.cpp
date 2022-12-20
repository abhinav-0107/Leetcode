// Recursion

// class Solution {
// public:
//     int mod=1e9+7;
//     vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
//     int dfs(int i,int j,vector<vector<int>>& mat,int m,int n){
//         int count=1;
//         for(auto d:dir){
//             int r=i+d.first;
//             int c=j+d.second;
//             if(r<m && r>=0 && c<n && c>=0 && mat[r][c]>mat[i][j]){
//                 count+=dfs(r,c,mat,m,n);
//             }
//         }
//         return count;
//     }
    
//     int countPaths(vector<vector<int>>& mat) {
//         int m=mat.size();
//         int n=mat[0].size();
//         int count=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 count+=dfs(i,j,mat,m,n);
//             }
//         }
//         return count;
//     }
// };

// Memoization

class Solution {
public:
    int mod=1e9+7;
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(int i,int j,vector<vector<int>>& mat,int m,int n,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int count=1;
        for(auto d:dir){
            int r=i+d.first;
            int c=j+d.second;
            if(r<m && r>=0 && c<n && c>=0 && mat[r][c]>mat[i][j]) count+=dfs(r,c,mat,m,n,dp)%mod;
        }
        return dp[i][j]=count;
    }
    
    int countPaths(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        long long count=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) count+=dfs(i,j,mat,m,n,dp)%mod;
        }
        return count%mod;
    }
};