class Solution {
public:
    set<vector<int>>a;
    void f(int i,vector<int>& nums,vector<int>& t,int n){
        if(i==n){
            if(t.size()>=2)a.insert(t);
            return;
        }
//      Pick
        if(!t.empty() && nums[i]>=t.back()){
            t.push_back(nums[i]);
            f(i+1,nums,t,n);
            t.pop_back();
        } 
        else if(t.empty()){
            t.push_back(nums[i]);
            f(i+1,nums,t,n);
            t.pop_back();
        }
//      Not Pick
        f(i+1,nums,t,n);
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>t;
        vector<vector<int>>ans;
        f(0,nums,t,nums.size());
        for(auto i:a)ans.push_back(i);
        return ans;
    }
};