class Solution {
public:
    vector<vector<int>>ans;
    void per(int i,vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            per(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        per(0,nums);
        return ans;
    }
};