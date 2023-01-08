class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a dictionary to store the indices of the elements
        std::unordered_map<int, int> indices;
        // iterate through the list of nums
        for (int i = 0; i < nums.size(); i++) {
            // if target - num is in indices, return the indices of the two elements
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            // if target - num is not in indices, store the index of num in indices
            indices[nums[i]] = i;
        }
        return {};
    }
};
