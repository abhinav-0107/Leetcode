class Solution {
public:
    void subSequences (int i, vector<int>& subSeq , vector<vector<int>>& ans, vector<int>& nums, int n){
        if(i == n){
            ans.push_back(subSeq);
            return;
        }
        
//         Pick
        subSeq.push_back(nums[i]);
        subSequences(i+1, subSeq, ans, nums, n);
        subSeq.pop_back();
//         Not-Pick
        subSequences(i+1, subSeq, ans, nums, n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subSeq;
        subSequences(0, subSeq, ans, nums, n);
        return ans;
    }
};



// [] , [1] , [2] , [3] , [1,2] , [2,3] , [1,3] , [1,2,3] 

// Number of sets => 8
// Number of Subsequesnce => 2^3 = 8