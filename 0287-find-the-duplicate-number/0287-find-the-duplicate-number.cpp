class Solution {
public:
    
    // int findDuplicate(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size();i++){
    //         int ans= nums[i]^nums[i+1];
    //         if(ans==0){
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }
    
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int high=n;
        int low=1;
        int count=0;
        while(low<=high){
            int mid=(low+high)/2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            if(count>mid){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            count=0;
        }
        return low;
        
    }
};