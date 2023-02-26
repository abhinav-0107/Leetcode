class Solution {
public:
    int f(int i,int j,string& w1,string& w2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
//      Match
        if(w1[i]==w2[j]) return dp[i][j]=f(i-1,j-1,w1,w2,dp);
//      NotMatch   
        int insert=1+f(i,j-1,w1,w2,dp);
        int deletion=1+f(i-1,j,w1,w2,dp);
        int replace=1+f(i-1,j-1,w1,w2,dp);
        return dp[i][j]=min(replace,min(insert,deletion));
    }
    
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,w1,w2,dp);
    }
};


// class Solution {
// public:
//     int minDistance(string w1, string w2) {
//         int n=w1.size();
//         int m=w2.size();
//         vector<int> prev(m+1,0),curr(m+1,0);
//         for(int j=0;j<=m;j++) prev[j]=j;
//         for(int i=1;i<=n;i++){
//             curr[0]=i;
//             for(int j=1;j<=m;j++){
//                 if(w1[i-1]==w2[j-1]) curr[j]=prev[j-1];
//                 else{
//                     int insert=1+curr[j-1];
//                     int deletion=1+prev[j];
//                     int replace=1+prev[j-1];
//                     curr[j]=min(replace,min(insert,deletion));
//                 }
//             }
//             prev=curr;
//         }
//         return prev[m];
//     }
// }; 


// class Solution {
// public:
//      int minDistance(string w1, string w2) {
//         int n=w1.size();
//         int m=w2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int j=0;j<=m;j++) dp[0][j]=j;
//         for(int i=0;i<=n;i++) dp[i][0]=i;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
//                 else{
//                     int insert=1+dp[i][j-1];
//                     int deletion=1+dp[i-1][j];
//                     int replace=1+dp[i-1][j-1];
//                     dp[i][j]=min(replace,min(insert,deletion));
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };

