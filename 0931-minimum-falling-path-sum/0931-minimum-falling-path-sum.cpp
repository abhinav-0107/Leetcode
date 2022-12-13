//Recursion (TLE)

// class Solution {
// public:
//     int f(int i,int j,vector<vector<int>>& mat){
//         if(j<0 || j>=mat.size()) return 1e6;
//         if(i==mat.size()-1) return mat[i][j];
//         int left = mat[i][j] + f(i+1,j-1,mat); 
//         int down = mat[i][j] + f(i+1,j,mat);
//         int right = mat[i][j] + f(i+1,j+1,mat);
//         return min(down,min(left,right)); 
//     }
    
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int ans=INT_MAX;
//         for(int j=0;j<n;j++) ans=min(ans,f(0,j,mat));
//         return ans;
//     }
// };


//Memoization

class Solution {
public:
    int f(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(j<0 || j>=mat.size()) return 1e6;
        if(i==mat.size()-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left = mat[i][j] + f(i+1,j-1,mat,dp); 
        int down = mat[i][j] + f(i+1,j,mat,dp);
        int right = mat[i][j] + f(i+1,j+1,mat,dp);
        return dp[i][j] = min(down,min(left,right)); 
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++) ans=min(ans,f(0,j,mat,dp));
        return ans;
    }
};


//Tabulation

// class Solution {
// public:    
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int n=mat.size();
//         vector<vector<int>>dp(n,vector<int>(n,0));
//         for(int j=0;j<n;j++) dp[n-1][j]=mat[n-1][j];
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<n;j++){
//                 int left=INT_MAX,right=INT_MAX;
//                 if(j>0) left = mat[i][j] + dp[i+1][j-1]; 
//                 int down = mat[i][j] + dp[i+1][j];
//                 if(j<n-1) right = mat[i][j] + dp[i+1][j+1];
//                 dp[i][j] = min(down,min(left,right));
//             }
//         }
//         return *min_element(dp[0].begin(),dp[0].end());
//     }
// };

//Space optimization

// class Solution {
// public:    
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int n=mat.size();
//         vector<int> prevrow(n);
//         for(int j=0;j<n;j++) prevrow[j]=mat[n-1][j];
//         for(int i=n-2;i>=0;i--){
//             vector<int> currrow(n);
//             for(int j=0;j<n;j++){
//                 int left=INT_MAX,right=INT_MAX;
//                 if(j>0) left = mat[i][j] + prevrow[j-1]; 
//                 int down = mat[i][j] + prevrow[j];
//                 if(j<n-1) right = mat[i][j] + prevrow[j+1];
//                 currrow[j] = min(down,min(left,right));
//             }
//             prevrow=currrow;
//         }
//         return *min_element(prevrow.begin(),prevrow.end());
//     }
// };