class Solution {
public:
    bool f(int i,int j,string& s,int& maxi,int& start,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) dp[i][j]=f(i+1,j-1,s,maxi,start,dp);
        else dp[i][j]=0;
        if(dp[i][j]){
            if(j-i+1>maxi){
                maxi=j-i+1;
                start=i;
            }
        }
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=1,start=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool t=f(i,j,s,maxi,start,dp);
            }
        }
        return s.substr(start,maxi);
    }
};