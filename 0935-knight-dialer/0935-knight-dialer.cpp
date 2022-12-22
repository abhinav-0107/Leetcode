// Recursion

// class Solution {
// public:
//     vector<pair<int,int>> dir{{-2,-1},{-2,1},{2,-1},{2,1},{-1,2},{1,2},{-1,-2},{1,-2}};
//     int mod=1e9+7;
//     int dfs(int i,int j,int n){
//         if(!n) return 1;
//         int ans=0;
//         for(auto d:dir){
//             int r=i+d.first;
//             int c=j+d.second;
//             if(r<3 && r>=0 && c<3 && c>=0) ans+=dfs(r,c,n-1)%mod;
//             else if(r==3 && c==1) ans+=dfs(r,c,n-1)%mod;
//         }
//         return ans%mod;
//     }
    
//     int knightDialer(int n) {
//         int count=0;
//         for(int i=0;i<4;i++){
//             for(int j=0;j<3;j++){
//                 if((i==3 && j==0) || (i==3 && j==2)) continue;
//                 count+=dfs(i,j,n-1)%mod;
//             }
//         }
//         return count%mod;
//     }
// };


//Memoization

class Solution {
public:
    vector<pair<int,int>> dir{{-2,-1},{-2,1},{2,-1},{2,1},{-1,2},{1,2},{-1,-2},{1,-2}};
    int mod=1e9+7;
    int dfs(int i,int j,int n,vector<vector<vector<int>>>& dp){
        if(!n) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        long long ans=0;
        for(auto d:dir){
            int r=i+d.first;
            int c=j+d.second;
            if(r<3 && r>=0 && c<3 && c>=0) ans+=dfs(r,c,n-1,dp)%mod;
            else if(r==3 && c==1) ans+=dfs(r,c,n-1,dp)%mod;
        }
        return dp[i][j][n]=ans%mod;
    }
    
    int knightDialer(int n) {
        long long count=0;
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if((i==3 && j==0) || (i==3 && j==2)) continue;
                count+=dfs(i,j,n-1,dp)%mod;
            }
        }
        return count%mod;
    }
};