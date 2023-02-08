class Solution {
public:
    int f(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i>=n-1) return 0;    
        if(dp[i]!=-1) return dp[i];
        int mini=1e9;
        for(int j=1;j<=nums[i];j++){
            mini=min(mini,1+f(i+j,nums,n,dp));
        }
        return dp[i]=mini;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }
};