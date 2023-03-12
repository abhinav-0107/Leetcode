class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, prefix = 0;
        
        unordered_map<int, long long> freq{{0, 1}};
        
        for (int i = 0; i < n; i++) {
            prefix ^= nums[i];
            
            if (freq.count(prefix)) {
                ans += freq[prefix];
            }
            
            freq[prefix]++;
        }
        
        return ans;
    }
};