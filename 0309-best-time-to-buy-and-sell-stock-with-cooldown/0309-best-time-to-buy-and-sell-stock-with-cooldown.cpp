// Recursion

// class Solution {
// public:
//     int f(int i,int b,vector<int>& p,int n){
//         if(i>=n) return 0;
//         int profit;
//         if(b){
//             int buy=-p[i]+f(i+1,0,p,n);
//             int notbuy=f(i+1,1,p,n);
//             profit=max(buy,notbuy);
//         }
//         else{
//             int sell=p[i]+f(i+2,1,p,n);
//             int notsell=f(i+1,0,p,n);
//             profit=max(sell,notsell);
//         }
//         return profit;
//     }
    
//     int maxProfit(vector<int>& p) {
//         int n=p.size();
//         return f(0,1,p,n);
//     }
// };


// Memoization

class Solution {
public:
    int f(int i,int b,vector<int>& p,int n,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        int profit;
        if(b){
            int buy=-p[i]+f(i+1,0,p,n,dp);
            int notbuy=f(i+1,1,p,n,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=p[i]+f(i+2,1,p,n,dp);
            int notsell=f(i+1,0,p,n,dp);
            profit=max(sell,notsell);
        }
        return dp[i][b]=profit;
    }
    
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,p,n,dp);
    }
};


// Tabulation

// class Solution {
// public:
// int maxProfit(vector<int>& p) {
//         int n=p.size();
//         vector<vector<int>> dp(n+2,vector<int>(2,0));
//         for(int i=n-1;i>=0;i--){
//             for(int b=0;b<=1;b++){
//                 int profit;
//                 if(b){
//                     int buy=-p[i]+dp[i+1][0];
//                     int notbuy=dp[i+1][1];
//                     profit=max(buy,notbuy);
//                 }
//                 else{
//                     int sell=p[i]+dp[i+2][1];
//                     int notsell=dp[i+1][0];
//                     profit=max(sell,notsell);
//                 }
//                 dp[i][b]=profit;
//             }
//         }
//         return dp[0][1];
//     }
// };