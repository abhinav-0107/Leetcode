class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int k=1;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second==2){
                ans.push_back(i.first);
                break;
            }
        }
        for(auto i:mp){
            if(i.first!=k){
                ans.push_back(k);
                break;
            }
            k++;
        }
        if(k==n && ans.size()==1){
            ans.push_back(k);
        }
        return ans;
    }
};