class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int neg=0,zero=0;
        for(auto i:nums){
            if(i<0) neg++;
            if(i==0) zero++;
        }
        if(zero>0) return 0;
        if(neg%2!=0) return -1;
        return 1;
    }
};