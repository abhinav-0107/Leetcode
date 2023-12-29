class Solution {
public:
    int f(int i,vector<int>& job,int d,int n,vector<vector<int>>& dp){
        if(d<0) return 1e9;
        if(i==n){
            if(!d) return 0;
            return 1e9;
        }    
        if(dp[i][d]!=-1) return dp[i][d];
        int maxi=-1e9,mini=1e9,pick=0;
        for(int j=i;j<n;j++){
            maxi=max(maxi,job[j]);
            pick=maxi+f(j+1,job,d-1,n,dp);
            mini=min(mini,pick);
        }
        return dp[i][d]=mini;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return f(0,job,d,n,dp);
    }
};