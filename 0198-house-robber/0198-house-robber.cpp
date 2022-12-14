//Recursion
// class Solution {
// public:
//     int subseq(int i,vector<int>& nums){
//         if(i>=nums.size()){
//             return 0;
//         }    
//         int pick=nums[i] + subseq(i+2,nums);
//         int notPick=subseq(i+1,nums);
//         return max(pick,notPick);
//     }
    
//     int rob(vector<int>& nums) {
//         return subseq(0,nums); 
//     }
// };


// Memoization
class Solution {
public:
    int subseq(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i] + subseq(i+2,nums,dp);
        int notPick=subseq(i+1,nums,dp);
        return dp[i]=max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return subseq(0,nums,dp); 
    }
};


//Tabulation
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size());
//         dp[0]=nums[0];
//         for(int i=1;i<nums.size();i++){
//             int pick=nums[i];
//             if(i!=1)pick+=dp[i-2];
//             int notpick=dp[i-1];
//             dp[i]=max(pick,notpick);
//         }
//         return dp[nums.size()-1];
//     }
// };


//Space Optimization
    // class Solution {
    // public:
    //     int rob(vector<int>& nums) {
    //         int p1=nums[0],p2=0;
    //         for(int i=1;i<nums.size();i++){
    //             int pick=nums[i];
    //             if(i!=1)pick+=p2;
    //             int notpick=p1;
    //             int curri=max(pick,notpick);
    //             p2=p1;
    //             p1=curri;
    //         }
    //         return p1;
    //     }
    // };