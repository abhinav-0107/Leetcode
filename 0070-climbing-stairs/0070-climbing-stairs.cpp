// Memoization
class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n]; 
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};

// Tabulation

// class Solution {
// public:
//     int climbStairs(int n){
//         vector<int> dp(n+1);
//         dp[0]=dp[1]=1;
//         for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
//         return dp[n];
//     }
// };

// Space-optimization
// class Solution {
// public:
//     int climbStairs(int n){
//         if(n==1 || n==0)return 1;
//         int pre1=1,pre2=1,ans;
//         for(int i=2;i<=n;i++){
//             ans=pre1+pre2;
//             pre2=pre1;
//             pre1=ans;
//         }    
//         return ans;
//     }
// };
    