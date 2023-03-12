class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum > 0) ans++;
        }
        return ans;
    }
};