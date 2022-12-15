//Recursion

// class Solution {
// public:
//     int f(int i1,int i2,string& s1,string& s2){
//         if(i1<0 || i2<0) return 0;
//         if(s1[i1]==s2[i2]) return 1+f(i1-1,i2-1,s1,s2);
//         return max(f(i1-1,i2,s1,s2),f(i1,i2-1,s1,s2));
//     }

//     int longestCommonSubsequence(string s1, string s2) {
//          return f(s1.size()-1,s2.size()-1,s1,s2);  
//     }
// };


//Memoization

class Solution {
public:
    int f(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s1[i1]==s2[i2]) return dp[i1][i2]=1+f(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2]=max(f(i1-1,i2,s1,s2,dp),f(i1,i2-1,s1,s2,dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
         return f(n-1,m-1,s1,s2,dp);  
    }
};


//Tabulation

// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         int n=s1.size(),m=s2.size();
//         vector<vector<int>> dp(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!i  || !j){
//                     if(s1[i]==s2[j]) dp[i][j]=1;
//                     else{
//                         if(!i && !j) dp[0][0]=0;
//                         else if(!i && j) dp[0][j]=dp[0][j-1];
//                         else if(i && !j) dp[i][0]=dp[i-1][0];
//                     }
//                 }
//                 else{
//                     if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
//                     else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n-1][m-1];  
//     }
// };