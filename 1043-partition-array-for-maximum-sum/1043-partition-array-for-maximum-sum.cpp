class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+k,0);
        for(int i=n+k-1;i>=0;i--){
            int ans=0;
            for(int j=0;j<k && i+j<n;j++){
                int maxi=*max_element(arr.begin()+i,arr.begin()+i+j+1);
                int op=(j+1)*maxi+dp[i+j+1];
                ans=max(ans,op);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
