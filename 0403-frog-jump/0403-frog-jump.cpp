// Recursion!

// class Solution {
// public:
//     bool f(int i,int k,vector<int>& st,int n){
//         if(i==n-1) return true;
//         bool neg=false,pos=false,equ=false;
        
//         int i1=lower_bound(st.begin(),st.end(),st[i]+k-1)-st.begin();
//         if(k>0 && i1<n && st[i1]==st[i]+k-1) neg=f(i1,k-1,st,n);
        
//         int i2=lower_bound(st.begin(),st.end(),st[i]+k)-st.begin();
//         if(k>0 && i2<n && st[i2]==st[i]+k) equ=f(i2,k,st,n);
        
//         int i3=lower_bound(st.begin(),st.end(),st[i]+k+1)-st.begin();
//         if(i3<n && st[i3]==st[i]+k+1) pos=f(i3,k+1,st,n);
        
//         return equ || neg || pos;
//     }
    
//     bool canCross(vector<int>& stones) {
//         int n=stones.size();
//         return f(0,0,stones,n);
//     }
// };

// Memoization!

class Solution {
public:
    bool f(int i,int k,vector<int>& st,int n,vector<vector<int>>& dp){
        if(i==n-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        bool neg=false,pos=false,equ=false;
        
        int i1=lower_bound(st.begin(),st.end(),st[i]+k-1)-st.begin();
        if(k>0 && i1<n && st[i1]==st[i]+k-1) neg=f(i1,k-1,st,n,dp);
        
        int i2=lower_bound(st.begin(),st.end(),st[i]+k)-st.begin();
        if(k>0 && i2<n && st[i2]==st[i]+k) equ=f(i2,k,st,n,dp);
        
        int i3=lower_bound(st.begin(),st.end(),st[i]+k+1)-st.begin();
        if(i3<n && st[i3]==st[i]+k+1) pos=f(i3,k+1,st,n,dp);
        
        return dp[i][k]=equ || neg || pos;
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,0,stones,n,dp);
    }
};