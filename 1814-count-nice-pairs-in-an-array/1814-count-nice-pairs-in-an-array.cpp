class Solution {
public:
    int mod=(1e9+7);
    int rev(string n){
        reverse(n.begin(),n.end());
        return stoi(n);
    }
    
    int countNicePairs(vector<int>& nums) {
        long long count=0;
        map<int,long long>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]-rev(to_string(nums[i]))]++;
        for(auto i:mp)count+=((i.second)*(i.second-1))/2;
        return count%mod;
    }
};