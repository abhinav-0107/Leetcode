class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1;
        long long ans = 0;
        
        while(j > i){
            string temp = to_string(nums[i]) + to_string(nums[j]);
            i++;
            j--;
            ans += stoll(temp);
        }
        
        if(n % 2 == 1) ans += nums[i];
        
        return ans;
    }
};