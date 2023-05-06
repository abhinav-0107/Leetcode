class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7,n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> p(n,1);
        for(int i=1;i<n;i++) p[i]=(2*p[i-1])%mod;
        int i=0,j=n-1;
        long long count=0;
        while(j>=i){
            if(nums[i]+nums[j]<=target){
                count+=p[j-i];
                i++;
            }
            else j--;
        }
        return count%mod;   
    }
};