class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int maxFreq = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            maxFreq = max(maxFreq,mp[nums[i]]);
        }
        for(auto it : mp){
            if(it.second == maxFreq) count++;
        }
        return count*maxFreq;
    }
};