class Solution {
public:
    int f(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s1[i1]==s2[i2]) return dp[i1][i2]=1+f(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2]=max(f(i1-1,i2,s1,s2,dp),f(i1,i2-1,s1,s2,dp));
    }

    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        string s2=string(s1.rbegin(),s1.rend());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(n-1,n-1,s1,s2,dp); 
    }
};