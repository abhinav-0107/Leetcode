// Recursion

// class Solution {
// public:
//     bool f(int i,vector<int>& nums,int n){
//         if(i==n-1) return true;
//         for(int j=1;j<=nums[i];j++){
//             if(f(i+j,nums,n)) return true;
//         }
//         return false;
//     }
    
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         return f(0,nums,n);
//     }
// };


//Memoization

class Solution {
public:
    bool f(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i==n-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(f(i+j,nums,n,dp)) return dp[i]=true;
        }
        return dp[i]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }
};