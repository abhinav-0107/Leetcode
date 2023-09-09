class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,1);
        for(int t=1;t<=target;t++){
            long long ways=0;
            for(int i=0;i<n;i++){
                if(t>=nums[i]) ways+=dp[t-nums[i]];
            }
            dp[t]=ways;
        }
        return dp[target];
    }
};