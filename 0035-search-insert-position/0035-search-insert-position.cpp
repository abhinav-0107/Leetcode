class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(target>nums[n-1]){
            return n;
        }
        else if(target<nums[0]){
            return 0;
        }
        
        int low=0,high=n-1;
        while(low<=high){

            int mid=(low+high)/2;
            
            if(nums[mid]==target){             
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            if(nums[mid]>target && target>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]<target && target<nums[mid+1]){
                return mid+1;
            }
        }
        return -1; 
    }
};